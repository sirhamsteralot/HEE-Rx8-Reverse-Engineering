/* ROM address: 0x000015a6; body bytes: 98; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 000015a6 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000015a6(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  ushort uVar3;
  byte bVar4;
  
  uVar3 = (*param_1 & 0xf) * 0x100 + (ushort)param_1[1];
  if (uVar3 < 8) {
    uVar2 = 0xffffffff;
  }
  else {
    bVar4 = 3;
    DAT_ffffd3f2 = uVar3 - 1;
    DAT_ffffd3f0 = param_1[2];
    _DAT_ffffdfac = 0;
    param_1 = param_1 + 3;
    do {
      bVar4 = bVar4 + 1;
      bVar1 = *param_1;
      param_1 = param_1 + 1;
      (&DAT_ffffd3f4)[_DAT_ffffdfac] = bVar1;
      _DAT_ffffdfac = _DAT_ffffdfac + 1;
    } while (bVar4 < 8);
    _DAT_ffffdfae = 0;
    uVar2 = 0;
  }
  return uVar2;
}


