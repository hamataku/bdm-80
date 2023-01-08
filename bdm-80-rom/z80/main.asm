.z80
.area TEST(ABS)

.org	0x0000
start:
  ld hl,#0x100
  ld a,(hl)
  ld hl,#0x101
  ld b,(hl)
  ld h,a
  ld l,b
  jp (hl)

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