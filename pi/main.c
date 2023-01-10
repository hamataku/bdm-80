#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;

/* size バイトの dest[] に src[] を足す */
void MPAdd(u8 dest[], u8 src[], int size)
{
    int i;
    int carry = 0;
    for (i = size - 1; i >= 0; i--) {
        int n = dest[i] + src[i] + carry;
        carry = (n >> 8) & 1;
        dest[i] = (u8)n;
    }
    return;
}

/* size バイトの dest[] から src[] を引く */
void MPSub(u8 dest[], u8 src[], int size)
{
    int i;
    int carry = 0;
    for (i = size - 1; i >= 0; i--) {
        int n = dest[i] - src[i] - carry;
        carry = (n >> 8) & 1;
        dest[i] = (u8)n;
    }
    return;
}

/* size バイトの src[] を d で割って dest[] に格納する */
void MPDiv(u8 dest[], u8 src[], int d, int size)
{
    int i, j;
    int r = 0;
    for (i = 0; i < size; i++) {
        u8 q = 0;
        u8 n = src[i];
        for (j = 0; j < 8; j++) {
            r <<= 1;
            if ((n & 0x80) != 0) {
                r++;
            }
            q <<= 1;
            if (r >= d) {
                r -= d;
                q++;
            }
            n <<= 1;
        }
        dest[i] = q;
    }
    return;
}

/* binSize バイトの bin[] を packed BCD に変換して
   bcdSize バイトの bcd[] に格納する
   ただし bin[], bcd[] は小数部とする */
void Bin2Bcd(u8 bcd[], int bcdSize, u8 bin[], int binSize)
{
    int i, j;
    for (i = 0; i < bcdSize; i++) {
        int n = 0;
        for (j = binSize - 1; j >= 0; j--) {
            int m = bin[j] * 100 + n;
            bin[j] = (u8)m;
            n = m >> 8;
        }
        bcd[i] = (u8)(((n / 10) << 4) + (n % 10));
    }
    return;
}

int binSize = 8;
int bcdSize = 3;
int i;
u8 *work1, *work2, *work3, *work4, *bcdResult;
int work2Skip, d;

void display()
{
    bcdResult[0] = work1[0];
    memcpy(work4, work1, binSize);
    Bin2Bcd(&bcdResult[1], bcdSize, &work4[1], binSize - 1);

    printf("%d.", bcdResult[0]);
    for (i = 0; i < bcdSize; i++) {
        printf("%02x", bcdResult[1 + i]);
        if (((i + 1) % 5) == 0) {
            if (((i + 1) % 25) == 0) {
                printf("\n");
            } else {
                printf(" ");
            }
        }
    }
    if ((i % 25) != 0) {
        printf("\n");
    }
}

int main()
{
    work1 = (u8*)malloc(binSize);
    work2 = (u8*)malloc(binSize);
    work3 = (u8*)malloc(binSize);
    work4 = (u8*)malloc(binSize);
    bcdResult = (u8*)malloc(1 + bcdSize);

    memset(work2, 0, binSize);
    work2[0] = 16;
    MPDiv(work2, work2, 5, binSize);
    memcpy(work1, work2, binSize);
    work2Skip = 0;
    d = 1;

    display();

    do {
        MPDiv(work2, work2, 5 * 5, binSize);
        d += 2;
        MPDiv(work3, work2, d, binSize);
        if ((d & 2) == 0) {
            MPAdd(work1, work3, binSize);
        } else {
            MPSub(work1, work3, binSize);
        }
        while (work2Skip < binSize) {
            if (work2[work2Skip] != 0) {
                break;
            }
            work2Skip++;
        }
        display();
    } while (work2Skip < binSize);

    memset(work2, 0, binSize);
    work2[0] = 4;
    MPDiv(work2, work2, 239, binSize);
    MPSub(work1, work2, binSize);
    work2Skip = 0;
    d = 1;
    do {
        MPDiv(work2, work2, 239 * 239, binSize);
        d += 2;
        MPDiv(work3, work2, d, binSize);
        if ((d & 2) == 0) {
            MPSub(work1, work3, binSize);
        } else {
            MPAdd(work1, work3, binSize);
        }
        while (work2Skip < binSize) {
            if (work2[work2Skip] != 0) {
                break;
            }
            work2Skip++;
        }
        display();
    } while (work2Skip < binSize);

    display();

    free(bcdResult);
    free(work1);
    free(work2);
    free(work3);
    return 0;
}