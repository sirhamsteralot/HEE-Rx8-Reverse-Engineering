/* ROM address: 0x00000ace; body bytes: 26; decompiled */

byte FUN_00000ace(byte param_1,byte param_2,undefined1 *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  
  for (; param_2 < param_1; param_2 = param_2 + 1) {
    uVar1 = *param_4;
    param_4 = param_4 + 1;
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  }
  return param_1;
}


