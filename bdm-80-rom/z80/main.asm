.z80
.area TEST(ABS)

.org	0x0000
main:
  ld hl,#0xfffd
  ld (hl),#0x00
  ld hl,#0x100
  ld a,(hl)
  ld hl,#0x101
  ld b,(hl)
  ld h,a
  ld l,b
  jp (hl)
