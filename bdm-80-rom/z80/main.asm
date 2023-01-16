.z80
.AreA TEST(ABS)

PIOAD .EQU 0b1000
PIOAC .EQU 0b1010
PIOBD .EQU 0b1001
PIOBC .EQU 0b1011

DISPA .EQU 0xfffc
DISPD .EQU 0xfffe

SIOAD .EQU 0b0100
SIOAC .EQU 0b0110
SIOBD .EQU 0b0101
SIOBC .EQU 0b0111

.ORG	0x0000
START:
  LD HL,#0x100
  LD A,(HL)
  LD HL,#0x101
  LD B,(HL)
  LD H,A
  LD L,B
  JP (HL)

.ORG	0x1000
START1:
  LD BC,#0xffff
  LD A,#0b00001111 ; PIOBモード0
  OUT (#PIOBC),A
  LD D,#0x00
  LD HL,#0x00
LOOP1:
  INC BC
  LD (#DISPD),BC ;　データ表示部にBCを出力
  ; check BC is 0
  LD A,B
  OR C
  JR NZ,LOOP1
  ; BC = 0
  LD A,#0x01
  XOR D
  LD D,A
  OUT (#PIOBD),A
  LD (#DISPA),HL ; アドレス表示部にHLを出力
  INC HL
  JP LOOP1

.ORG	0x2000
start2:
	ld	sp,#0x0000
	call	sioinit
main2:
	ld	a,#"O"
	call	com_out
	ld	a,#"K"
	call	com_out
loop2:
  call	com_in
	call	com_out
	jr	loop2
sioinit:
	ld	b,#0x0b
	ld	c,#SIOBC
	ld	hl,#SIO_INIT_TB_B
	otir
	ld	b,#0x09
	ld	c,#SIOAC
	ld	hl,#SIO_INIT_TB_A
	otir	
	ret
	
com_in:	
  in  a,(SIOAC)
	bit	0,a
  jr  z,com_in
	in  a,(SIOAD)
	ret

com_out:
  push	af
com_out01:
	in  a,(SIOAC)
  bit  2,a
  jr  z,com_out01
	pop	af
  out  (SIOAD),a
	ret

SIO_INIT_TB_A:
	.db	0x18		;ch RESET
	.db	0x14		;WR4 set ,int reset
	.db	0b01000100	;x16 8bitchar 1stopbit nonparity
	.db	0x03		;WR3 set
	.db	0b11000001	;rx 8bit char ,RxEnable
	.db	0x05		;WR5 set
	.db	0b01101000	;tx 8bit char ,TxEnable ,DTR=0 ,RTS=0
	.db	0x11		;WR1 set ,int reset
	.db	0b00000000	;non int
SIO_INIT_TB_B:
	.db	0x18		;ch RESET
	.db	0x02		;WR2 set
	.db	0x00		;int tabel 0x00
	.db	0x14		;WR4 set ,int reset
	.db	0b01000100	;x16 8bitchar 1stopbit nonparity
	.db	0x03		;WR3 set
	.db	0b11000001	;rx 8bit char ,RxEnable
	.db	0x05		;WR5 set
	.db	0b01101000	;tx 8bit char ,TxEnable ,DTR=0 ,RTS=0
	.db	0x11		;WR1 set ,int reset
	.db	0b00000000	;non int