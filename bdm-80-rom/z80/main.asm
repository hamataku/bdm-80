.z80
.area TEST(ABS)

WORK1		.EQU 0x1000
WORK2		.EQU 0x6000
WORK3		.EQU 0xB000
BCD_RESULT	.EQU 0xf000
WORK_BASE_H	.EQU 0xA

WORK_BASE	.EQU WORK_BASE_H*0x100
PBIN_SIZE	.EQU 8

.ORG	0x0000
START:
  LD HL,#0x100
  LD A,(HL)
  LD HL,#0x101
  LD B,(HL)
  LD H,A
  LD L,B
  jp (HL)

.org	0x8000
main:
  ld bc,#0x0
loop:
  inc bc
  ld hl,#0xfffc
  ld (hl),b
  ld hl,#0xfffd
  ld (hl),c
  jp loop