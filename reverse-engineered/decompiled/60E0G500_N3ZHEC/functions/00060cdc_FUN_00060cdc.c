/* ROM address: 0x00060cdc; body bytes: 30; decompiled */

undefined2 * FUN_00060cdc(undefined2 param_1,char param_2)

{
  if (param_2 == ' ') {
    DAT_ffffd6ca = 3;
    DAT_ffffd6cc = 0xffff;
    DAT_ffffd6c8 = param_1;
  }
  else {
    DAT_ffffd6c8 = 0xffff;
  }
  return &DAT_ffffd6c8;
}


