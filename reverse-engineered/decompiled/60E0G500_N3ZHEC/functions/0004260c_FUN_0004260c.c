/* ROM address: 0x0004260c; body bytes: 158; decompiled */

undefined2 * FUN_0004260c(void)

{
  undefined2 *puVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc982 = 0;
    DAT_ffffc981 = 0;
    DAT_ffffc984 = 0;
    puVar1 = (undefined2 *)&UNK_00000001;
  }
  else {
    puVar1 = (undefined2 *)(uint)DAT_ffffc980;
    if (puVar1 != (undefined2 *)&UNK_00000001) {
      return puVar1;
    }
    if (DAT_ffffb3c4 < 90.0) {
      puVar1 = &DAT_ffffc986;
      if (DAT_ffffc986 < 0x80) {
        if (DAT_ffffc986 < 8) {
          DAT_ffffc982 = 0;
          DAT_ffffc981 = 1;
        }
      }
      else {
        DAT_ffffc982 = 1;
        DAT_ffffc981 = 0;
      }
    }
    if (DAT_ffffb3c4 < 10.0) {
      return puVar1;
    }
    puVar1 = &DAT_0007d9dc;
    if (DAT_ffffc988 < 0x80) {
      if (7 < DAT_ffffc988) {
        return &DAT_0007d9dc;
      }
      DAT_ffffc983 = 1;
      DAT_ffffc984 = 0;
      return &DAT_0007d9dc;
    }
    DAT_ffffc984 = 1;
  }
  DAT_ffffc983 = 0;
  return puVar1;
}


