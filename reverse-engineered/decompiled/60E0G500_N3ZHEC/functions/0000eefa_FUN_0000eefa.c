/* ROM address: 0x0000eefa; body bytes: 372; decompiled */

undefined * FUN_0000eefa(void)

{
  undefined *puVar1;
  
  if (DAT_ffffb5b8 < 5500.0) {
    if (DAT_ffffb5b8 < 5300.0) {
      DAT_ffffa4ab = 0;
    }
  }
  else {
    DAT_ffffa4ab = 1;
  }
  if (DAT_ffffb5b8 < 9000.0) {
    if (DAT_ffffb5b8 < 8800.0) {
      DAT_ffffa4ac = 0;
    }
  }
  else {
    DAT_ffffa4ac = 1;
  }
  if ((((DAT_ffffa4a6 == '\x01') || (DAT_ffffa4aa == 1)) &&
      (puVar1 = &UNK_00000001, DAT_ffffa4ab == 0)) ||
     (((DAT_ffffa4a6 == '\0' && (puVar1 = &DAT_ffffa4aa, DAT_ffffa4aa == 0)) && (DAT_ffffa4ac == 0))
     )) {
    DAT_ffffa4a5 = 0;
    DAT_ffffa4a4 = 0;
    DAT_ffffa4a8 = 0;
  }
  else {
    if ((((DAT_ffffa4a6 == '\x01') || (DAT_ffffa4aa == 1)) && (DAT_ffffa4ab == 1)) ||
       (((DAT_ffffa4a6 == '\0' && (DAT_ffffa4aa == 0)) && (DAT_ffffa4ac == 1)))) {
      DAT_ffffa4a4 = 1;
      DAT_ffffa4a8 = FUN_00002460((int)DAT_ffffa4a8,1);
    }
    if (DAT_ffffb5aa == '\0') {
      if ((((DAT_ffffa4a6 == '\x01') && (DAT_ffffa4ab == 1)) &&
          (puVar1 = (undefined *)(int)DAT_ffffa4a8, &UNK_00000113 < puVar1)) ||
         (((puVar1 = (undefined *)(uint)DAT_ffffa4aa, puVar1 == &UNK_00000001 &&
           (puVar1 = (undefined *)(uint)DAT_ffffa4ab, puVar1 == &UNK_00000001)) ||
          ((DAT_ffffa4a6 == '\0' &&
           (((DAT_ffffa4aa == 0 &&
             (puVar1 = (undefined *)(uint)DAT_ffffa4ac, puVar1 == &UNK_00000001)) &&
            (puVar1 = (undefined *)(int)DAT_ffffa4a8, (undefined *)0x1c2 < puVar1)))))))) {
        DAT_ffffa4a5 = 1;
      }
    }
    else {
      puVar1 = (undefined *)(uint)DAT_ffffa4a4;
      if (puVar1 == &UNK_00000001) {
        DAT_ffffa4a5 = 1;
      }
    }
  }
  return puVar1;
}


