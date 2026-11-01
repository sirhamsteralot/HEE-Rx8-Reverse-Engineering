/* ROM address: 0x0003bdfe; body bytes: 98; decompiled */

undefined4 * FUN_0003bdfe(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)0x1;
  if ((((DAT_ffffd201 == '\x01') || (puVar1 = (undefined4 *)0x1, DAT_ffffd1e9 == '\x01')) ||
      (puVar1 = &DAT_0003bed4, DAT_ffffb360 < 8.0)) || (puVar1 = &DAT_0003bed4, 92.0 < DAT_ffffb360)
     ) {
    DAT_ffffc5f7 = 0;
  }
  else {
    puVar1 = (undefined4 *)(uint)DAT_ffffc5f3;
    if (puVar1 != (undefined4 *)0x1) {
      if (DAT_ffffc5ec == -1) {
        DAT_ffffc5f7 = 0;
        return puVar1;
      }
      DAT_ffffc5ec = DAT_ffffc5ec + '\x01';
      DAT_ffffc5f7 = 0;
      return puVar1;
    }
    DAT_ffffc5f7 = 1;
    puVar1 = (undefined4 *)&UNK_00000001;
  }
  DAT_ffffc5ec = 0;
  return puVar1;
}


