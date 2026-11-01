/* ROM address: 0x00013e0c; body bytes: 134; decompiled */

undefined4 * FUN_00013e0c(void)

{
  undefined4 *puVar1;
  
  if (DAT_ffffb5b8 < 8000.0) {
    if (DAT_ffffb5b8 < 7800.0) {
      DAT_ffffa787 = 1;
    }
  }
  else {
    DAT_ffffa787 = 0;
  }
  puVar1 = (undefined4 *)(uint)DAT_ffffa774;
  if ((((puVar1 == (undefined4 *)&UNK_00000001) && (DAT_ffffa772 != 0)) &&
      (puVar1 = (undefined4 *)(uint)DAT_ffffa787, puVar1 == (undefined4 *)&UNK_00000001)) &&
     (((DAT_ffffa778 < 0.5 && (puVar1 = &DAT_00072d64, 0.1 <= DAT_ffffc12c)) &&
      ((puVar1 = (undefined4 *)(uint)DAT_ffffa768, puVar1 == (undefined4 *)&UNK_00000015 &&
       (puVar1 = (undefined4 *)(int)DAT_ffffa770, puVar1 == (undefined4 *)0x0)))))) {
    DAT_ffffa768 = 0;
  }
  DAT_ffffa778 = DAT_ffffc12c;
  return puVar1;
}


