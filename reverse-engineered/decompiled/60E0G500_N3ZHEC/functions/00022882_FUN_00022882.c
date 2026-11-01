/* ROM address: 0x00022882; body bytes: 96; decompiled */

undefined2 * FUN_00022882(void)

{
  undefined2 *puVar1;
  
  if (DAT_ffffaa10 < 65.0) {
    if (DAT_ffffaa10 < 62.5) {
      DAT_ffffb39c = 0;
    }
  }
  else {
    DAT_ffffb39c = 1;
  }
  puVar1 = &DAT_00073728;
  if ((((DAT_ffffa426 < 0x2d) ||
       (puVar1 = (undefined2 *)(uint)DAT_ffffb39c, puVar1 != (undefined2 *)&UNK_00000001)) ||
      (puVar1 = (undefined2 *)(int)DAT_ffffc600, puVar1 != (undefined2 *)0x0)) ||
     (puVar1 = (undefined2 *)&DAT_ffffcdb4, DAT_ffffcdb4 != '\0')) {
    DAT_ffffb388 = 0;
  }
  else {
    DAT_ffffb388 = 1;
  }
  return puVar1;
}


