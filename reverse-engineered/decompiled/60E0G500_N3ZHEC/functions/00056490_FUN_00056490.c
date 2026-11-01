/* ROM address: 0x00056490; body bytes: 86; decompiled */

undefined4 FUN_00056490(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x10);
  if (param_1 == '\0') {
    DAT_ffffd20e = 0x271;
    DAT_ffffd210 = 0;
    goto LAB_000564d8;
  }
  if (param_1 != '\x01') {
    if (param_1 == '\x02') {
      DAT_ffffd210 = 2;
      goto LAB_000564d8;
    }
    if (param_1 != '\x03') goto LAB_000564d8;
    DAT_ffffd20e = 0;
  }
  DAT_ffffd210 = 1;
LAB_000564d8:
  uVar1 = FUN_00003934(uVar1);
  return uVar1;
}


