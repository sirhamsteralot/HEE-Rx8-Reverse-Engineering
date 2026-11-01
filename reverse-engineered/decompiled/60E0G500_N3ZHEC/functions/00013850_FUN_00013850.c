/* ROM address: 0x00013850; body bytes: 168; decompiled */

undefined4 * FUN_00013850(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(uint)DAT_ffffa740;
  if ((((((puVar1 != (undefined4 *)0x1) || (DAT_ffffaa10 < 140.0)) || (150.0 <= DAT_ffffaa10)) ||
       ((DAT_ffffae54 < 40.0 || (100.0 <= DAT_ffffae54)))) ||
      ((DAT_ffffb5b8 < 500.0 || ((4600.0 <= DAT_ffffb5b8 || (DAT_ffffc12c < 0.5)))))) ||
     ((1.125 <= DAT_ffffc12c || (puVar1 = &DAT_ffffc1c0, 0.065 < DAT_ffffc1c0)))) {
    DAT_ffffa74a = 0;
    DAT_ffffa758 = 0;
  }
  else {
    if (0xf9 < DAT_ffffa758) {
      DAT_ffffa74a = 1;
    }
    puVar1 = (undefined4 *)FUN_00002460((int)(short)DAT_ffffa758,1);
    DAT_ffffa758 = (ushort)puVar1;
  }
  return puVar1;
}


