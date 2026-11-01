/* ROM address: 0x00007c68; body bytes: 268; decompiled */

undefined * FUN_00007c68(void)

{
  undefined *puVar1;
  byte bVar2;
  
  DAT_ffff9f97 = DAT_ffff9f97 + 1;
  if (0x17 < DAT_ffff9f97) {
    DAT_ffff9f97 = 0;
  }
  if (DAT_ffff9fca != 0xff) {
    if (DAT_ffff9f96 == 0) {
      DAT_ffff9f97 = DAT_ffff9fca;
      DAT_ffff9f96 = 1;
      FUN_00007668(1);
    }
    else if (DAT_ffff9fca != DAT_ffff9f97) {
      bVar2 = DAT_ffff9fca - DAT_ffff9f97;
      if (0x7f < bVar2) {
        bVar2 = bVar2 + 0x18;
      }
      if (bVar2 < 3) {
        while (bVar2 != 0) {
          FUN_00007fcc((int)(char)DAT_ffff9f97);
          FUN_0000a092(DAT_ffff9f97);
          DAT_ffff9f97 = DAT_ffff9f97 + 1;
          bVar2 = bVar2 - 1;
          if (0x17 < DAT_ffff9f97) {
            DAT_ffff9f97 = 0;
          }
        }
      }
      else {
        FUN_0000a13e(0);
      }
      DAT_ffff9f97 = DAT_ffff9fca;
    }
    DAT_ffff9fca = 0xff;
  }
  puVar1 = (undefined *)(uint)DAT_ffff9f96;
  if (puVar1 == &UNK_00000001) {
    FUN_00007fcc((int)(char)DAT_ffff9f97);
    FUN_0000a092(DAT_ffff9f97);
    puVar1 = &DAT_0000d7bc;
    if ((&DAT_0000d7bc)[DAT_ffff9f97] != -1) {
      puVar1 = (undefined *)FUN_0000768e();
      return puVar1;
    }
  }
  return puVar1;
}


