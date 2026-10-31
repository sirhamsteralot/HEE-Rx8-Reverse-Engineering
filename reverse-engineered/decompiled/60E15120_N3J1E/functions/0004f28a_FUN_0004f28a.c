/* ROM address: 0x0004f28a; body bytes: 52; decompiled */

uint FUN_0004f28a(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcfaa = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffcfbe;
    if (uVar1 == 1) {
      uVar1 = rx8_add_u16_saturate((int)DAT_ffffcfaa,1);
      DAT_ffffcfaa = (short)uVar1;
    }
  }
  return uVar1;
}


