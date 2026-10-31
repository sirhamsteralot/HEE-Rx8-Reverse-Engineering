/* ROM address: 0x00052c2c; body bytes: 94; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00050bb0 (94 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00052c2c(void)

{
  uint uVar1;
  
  uVar1 = 1;
  if (DAT_ffffd1c5 != '\x01') {
    if (DAT_ffffcfbf != 1) {
      return (uint)DAT_ffffcfbf;
    }
    if ((uint)(int)DAT_ffffcfaa <= (uint)(int)DAT_ffffcfa8) {
      return (int)DAT_ffffcfaa;
    }
    if ((int)DAT_ffffcff8 != 0) {
      return (int)DAT_ffffcff8;
    }
    uVar1 = 0;
    if (DAT_ffffcfe0 < DAT_ffffcfec - DAT_ffffd12c) {
      uVar1 = rx8_add_u8_saturate((int)DAT_ffffd130,1);
      DAT_ffffd130 = (char)uVar1;
      return uVar1;
    }
  }
  DAT_ffffd130 = 0;
  return uVar1;
}


