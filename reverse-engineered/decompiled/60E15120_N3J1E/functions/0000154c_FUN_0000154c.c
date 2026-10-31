/* ROM address: 0x0000154c; body bytes: 90; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 0000154c (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000154c(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  ushort uVar3;
  byte bVar4;
  byte *pbVar5;
  
  uVar3 = *param_1 & 0xf;
  if (((*param_1 & 0xf) == 0) || (7 < uVar3)) {
    uVar2 = 0xffffffff;
  }
  else {
    bVar4 = 2;
    DAT_ffffd3f2 = uVar3 - 1;
    pbVar5 = param_1 + 2;
    DAT_ffffd3f0 = param_1[1];
    _DAT_ffffdfac = 0;
    do {
      bVar4 = bVar4 + 1;
      bVar1 = *pbVar5;
      pbVar5 = pbVar5 + 1;
      (&DAT_ffffd3f4)[_DAT_ffffdfac] = bVar1;
      _DAT_ffffdfac = _DAT_ffffdfac + 1;
    } while (bVar4 < 8);
    uVar2 = 0;
  }
  return uVar2;
}


