/* ROM address: 0x0002c252; body bytes: 64; decompiled */

undefined * FUN_0002c252(void)

{
  undefined *puVar1;
  
  if ((DAT_ffffbc5e & 0x80) == 0x80) {
    puVar1 = (undefined *)(uint)DAT_ffffa428;
    if (puVar1 == &UNK_00000001) {
      DAT_ffffbc33 = 1;
      return puVar1;
    }
  }
  else {
    puVar1 = &DAT_00078d5e;
  }
  DAT_ffffbc33 = 0;
  return puVar1;
}


