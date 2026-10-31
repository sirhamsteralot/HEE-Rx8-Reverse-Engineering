/* ROM address: 0x0005b4e8; body bytes: 140; decompiled */

undefined4 FUN_0005b4e8(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (DAT_ffffd2e8 < 0xf0) {
    DAT_ffffd2e9 = 0;
    bVar1 = false;
    while ((DAT_ffffd2e9 < 6 && (!bVar1))) {
      if ((&DAT_0005f6dc)[(uint)DAT_ffffd2e9 * 0xc] == DAT_ffffd2e8) {
        bVar1 = true;
        if ((*(ushort *)(&DAT_0005f6e0 + (uint)DAT_ffffd2e9 * 0xc) & DAT_ffffd3b4) == 0) {
          uVar2 = 0x31;
        }
      }
      DAT_ffffd2e9 = DAT_ffffd2e9 + 1;
    }
    DAT_ffffd2e9 = DAT_ffffd2e9 - 1;
    if (!bVar1) {
      uVar2 = 0x31;
    }
  }
  else {
    uVar2 = 0x31;
  }
  return uVar2;
}


