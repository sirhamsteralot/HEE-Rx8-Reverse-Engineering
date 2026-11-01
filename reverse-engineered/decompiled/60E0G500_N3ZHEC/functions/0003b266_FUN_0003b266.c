/* ROM address: 0x0003b266; body bytes: 192; decompiled */

undefined * FUN_0003b266(void)

{
  undefined *puVar1;
  uint uVar2;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc5b2 = 0;
    DAT_ffffc5b3 = 0;
    DAT_ffffc5af = 0;
    DAT_ffffc5b0 = 0;
    puVar1 = &UNK_00000001;
  }
  else {
    if (DAT_ffffc5b1 == '\x01') {
      if (DAT_ffffc5b4 == '\x01') {
        DAT_ffffc5af = FUN_00002478((int)(char)DAT_ffffc5af,1);
      }
      else if (DAT_ffffc5b5 == '\x01') {
        DAT_ffffc5b0 = FUN_00002478((int)(char)DAT_ffffc5b0,1);
      }
    }
    puVar1 = (undefined *)(uint)DAT_ffffbfd4;
    if (puVar1 == &UNK_00000001) {
      puVar1 = &DAT_0007a7b8;
      if (DAT_ffffc5af < 0x28) {
        if (0x27 < DAT_ffffc5b0) {
          uVar2 = FUN_000671a4(0x2b);
          puVar1 = (undefined *)(uVar2 & 0xff);
          if (puVar1 == (undefined *)0x0) {
            DAT_ffffc5b3 = 1;
            DAT_ffffc5b2 = 0;
          }
        }
      }
      else {
        uVar2 = FUN_000671a4(0x2b);
        puVar1 = (undefined *)(uVar2 & 0xff);
        if (puVar1 == (undefined *)0x0) {
          DAT_ffffc5b2 = 1;
          DAT_ffffc5b3 = 0;
        }
      }
    }
  }
  return puVar1;
}


