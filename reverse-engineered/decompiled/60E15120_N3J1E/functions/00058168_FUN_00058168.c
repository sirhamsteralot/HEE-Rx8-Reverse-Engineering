/* ROM address: 0x00058168; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00056638 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00058168(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (uVar1 == 0) {
    DAT_ffffd228 = 1;
  }
  else {
    if (uVar1 != 1) {
      uVar1 = FUN_00057e72();
      return uVar1;
    }
    DAT_ffffd228 = 2;
  }
  return uVar1;
}


