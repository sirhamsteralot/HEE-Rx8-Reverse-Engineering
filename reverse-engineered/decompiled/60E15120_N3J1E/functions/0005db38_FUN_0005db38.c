/* ROM address: 0x0005db38; body bytes: 162; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005c328 (162 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005db38(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  
  DAT_ffffd373 = 0;
  bVar1 = false;
  while ((DAT_ffffd373 < 6 && (!bVar1))) {
    iVar2 = (uint)DAT_ffffd373 * 0xc;
    if ((&DAT_0005f6dc)[iVar2] == DAT_ffffd372) {
      bVar1 = true;
      if ((*(ushort *)(&DAT_0005f6e0 + iVar2) & DAT_ffffd3b4) == 0) {
        param_3 = 0x31;
      }
      else if ((byte)(&DAT_0005f6de)[iVar2] == DAT_ffffd370) {
        param_3 = 0;
      }
      else {
        param_3 = 0x12;
      }
    }
    DAT_ffffd373 = DAT_ffffd373 + 1;
  }
  if (bVar1) {
    DAT_ffffd373 = DAT_ffffd373 - 1;
  }
  else {
    param_3 = 0x31;
  }
  return param_3;
}


