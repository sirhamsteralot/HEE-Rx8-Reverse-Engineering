/* ROM address: 0x0004fce0; body bytes: 64; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004d8fc (64 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004fce0(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffd040;
  if ((((uVar1 == 1) && (uVar1 = (uint)DAT_ffffcfaa, 0x4e < uVar1)) &&
      (uVar1 = (uint)DAT_ffffd07f, uVar1 != 0)) && (DAT_ffffcff8 == '\0')) {
    DAT_ffffd047 = 1;
  }
  else {
    DAT_ffffd047 = 0;
  }
  DAT_ffffd07f = DAT_ffffcff8;
  return uVar1;
}


