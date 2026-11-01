/* ROM address: 0x0005e944; body bytes: 86; decompiled */

undefined4 FUN_0005e944(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x10);
  if (param_1 == '\0') {
    DAT_ffffd3c0 = 0x271;
    DAT_ffffd3c2 = 0;
    goto LAB_0005e98c;
  }
  if (param_1 != '\x01') {
    if (param_1 == '\x02') {
      DAT_ffffd3c2 = 2;
      goto LAB_0005e98c;
    }
    if (param_1 != '\x03') goto LAB_0005e98c;
    DAT_ffffd3c0 = 0;
  }
  DAT_ffffd3c2 = 1;
LAB_0005e98c:
  uVar1 = FUN_00003934(uVar1);
  return uVar1;
}


