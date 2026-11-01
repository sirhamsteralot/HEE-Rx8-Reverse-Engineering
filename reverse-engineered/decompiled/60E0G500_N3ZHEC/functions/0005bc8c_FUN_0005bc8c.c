/* ROM address: 0x0005bc8c; body bytes: 140; decompiled */

undefined4 FUN_0005bc8c(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (DAT_ffffd324 < 0xf0) {
    DAT_ffffd325 = 0;
    bVar1 = false;
    while ((DAT_ffffd325 < 6 && (!bVar1))) {
      if ((&DAT_0005fe80)[(uint)DAT_ffffd325 * 0xc] == DAT_ffffd324) {
        bVar1 = true;
        if ((*(ushort *)(&DAT_0005fe84 + (uint)DAT_ffffd325 * 0xc) & DAT_ffffd3f0) == 0) {
          uVar2 = 0x31;
        }
      }
      DAT_ffffd325 = DAT_ffffd325 + 1;
    }
    DAT_ffffd325 = DAT_ffffd325 - 1;
    if (!bVar1) {
      uVar2 = 0x31;
    }
  }
  else {
    uVar2 = 0x31;
  }
  return uVar2;
}


