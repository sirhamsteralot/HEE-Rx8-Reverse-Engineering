/* ROM address: 0x0005c2a4; body bytes: 86; decompiled */

undefined4 FUN_0005c2a4(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x10);
  if (param_1 == '\0') {
    DAT_ffffd34a = 0x271;
    DAT_ffffd34c = 0;
    goto LAB_0005c2ec;
  }
  if (param_1 != '\x01') {
    if (param_1 == '\x02') {
      DAT_ffffd34c = 2;
      goto LAB_0005c2ec;
    }
    if (param_1 != '\x03') goto LAB_0005c2ec;
    DAT_ffffd34a = 0;
  }
  DAT_ffffd34c = 1;
LAB_0005c2ec:
  uVar1 = FUN_00003934(uVar1);
  return uVar1;
}


