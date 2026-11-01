/* ROM address: 0x0003744c; body bytes: 156; decompiled */

undefined1 * FUN_0003744c(void)

{
  undefined *puVar1;
  undefined2 *puVar2;
  
  puVar1 = (undefined *)-((((int)DAT_ffffc243 & 0x80U) == 0) - 1);
  if (((puVar1 == &UNK_00000001) &&
      (puVar1 = (undefined *)(uint)DAT_ffffc242, puVar1 == &UNK_00000055)) &&
     (puVar1 = (undefined *)(uint)DAT_ffffc2b7, puVar1 == &UNK_00000001)) {
    puVar2 = (undefined2 *)((uint)DAT_ffffc244 * 600);
    if (&DAT_00010000 <= puVar2) {
      puVar2 = (undefined2 *)(undefined *)0xffff;
    }
    if (((uint)puVar2 & 0xffff) <= (uint)DAT_ffffc2a4) {
      DAT_ffffc242 = 0xaa;
      DAT_ffffc2b7 = 0;
      DAT_ffffc2ae = 1;
      DAT_ffffc2a6 = 0;
      return &DAT_ffffc2ae;
    }
    if (DAT_ffffc2a6 != 0xff) {
      DAT_ffffc2a6 = DAT_ffffc2a6 + 1;
    }
    if (0x18 < DAT_ffffc2a6) {
      if (DAT_ffffc2a4 != 0xffff) {
        DAT_ffffc2a4 = DAT_ffffc2a4 + 1;
      }
      DAT_ffffc2a6 = 0;
    }
  }
  return puVar1;
}


