/* ROM address: 0x0005e2dc; body bytes: 162; decompiled */

undefined4 FUN_0005e2dc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  
  DAT_ffffd3af = 0;
  bVar1 = false;
  while ((DAT_ffffd3af < 6 && (!bVar1))) {
    iVar2 = (uint)DAT_ffffd3af * 0xc;
    if ((&DAT_0005fe80)[iVar2] == DAT_ffffd3ae) {
      bVar1 = true;
      if ((*(ushort *)(&DAT_0005fe84 + iVar2) & DAT_ffffd3f0) == 0) {
        param_3 = 0x31;
      }
      else if ((byte)(&DAT_0005fe82)[iVar2] == DAT_ffffd3ac) {
        param_3 = 0;
      }
      else {
        param_3 = 0x12;
      }
    }
    DAT_ffffd3af = DAT_ffffd3af + 1;
  }
  if (bVar1) {
    DAT_ffffd3af = DAT_ffffd3af - 1;
  }
  else {
    param_3 = 0x31;
  }
  return param_3;
}


