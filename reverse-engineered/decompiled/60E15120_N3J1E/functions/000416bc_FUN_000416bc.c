/* ROM address: 0x000416bc; body bytes: 158; decompiled */

undefined2 * FUN_000416bc(void)

{
  undefined2 *puVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc912 = 0;
    DAT_ffffc911 = 0;
    DAT_ffffc914 = 0;
    puVar1 = (undefined2 *)((int)&vector_Poweron_Reset + 1);
  }
  else {
    puVar1 = (undefined2 *)(uint)DAT_ffffc910;
    if (puVar1 != (undefined2 *)((int)&vector_Poweron_Reset + 1)) {
      return puVar1;
    }
    if (DAT_ffffb354 < 90.0) {
      puVar1 = &DAT_ffffc916;
      if (DAT_ffffc916 < 0x80) {
        if (DAT_ffffc916 < 8) {
          DAT_ffffc912 = 0;
          DAT_ffffc911 = 1;
        }
      }
      else {
        DAT_ffffc912 = 1;
        DAT_ffffc911 = 0;
      }
    }
    if (DAT_ffffb354 < 10.0) {
      return puVar1;
    }
    puVar1 = &DAT_0007de10;
    if (DAT_ffffc918 < 0x80) {
      if (7 < DAT_ffffc918) {
        return &DAT_0007de10;
      }
      DAT_ffffc913 = 1;
      DAT_ffffc914 = 0;
      return &DAT_0007de10;
    }
    DAT_ffffc914 = 1;
  }
  DAT_ffffc913 = 0;
  return puVar1;
}


