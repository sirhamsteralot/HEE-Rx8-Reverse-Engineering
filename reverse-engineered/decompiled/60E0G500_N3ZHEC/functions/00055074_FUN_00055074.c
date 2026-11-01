/* ROM address: 0x00055074; body bytes: 28; decompiled */

undefined1 * FUN_00055074(undefined1 *param_1,char *param_2,undefined2 param_3)

{
  *param_2 = *param_2 + '\x01';
  *param_1 = (char)((ushort)param_3 >> 8);
  *param_2 = *param_2 + '\x01';
  param_1[1] = (char)param_3;
  return param_1 + 2;
}


