/* ROM address: 0x0004c3a0; body bytes: 120; decompiled */

uint FUN_0004c3a0(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffce98;
  if (uVar1 == 1) {
    if (DAT_ffffce97 == '\x01') {
      DAT_ffffce93 = rx8_add_u8_saturate((int)DAT_ffffce93,1);
    }
    if (DAT_ffffce94 == '\x01') {
      DAT_ffffce90 = rx8_add_u8_saturate((int)DAT_ffffce90,1);
    }
    if (DAT_ffffce95 == '\x01') {
      DAT_ffffce91 = rx8_add_u8_saturate((int)DAT_ffffce91,1);
    }
    uVar1 = (uint)DAT_ffffce96;
    if (uVar1 == 1) {
      uVar1 = rx8_add_u8_saturate((int)DAT_ffffce92,1);
      DAT_ffffce92 = (char)uVar1;
    }
  }
  return uVar1;
}


