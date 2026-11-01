/* ROM address: 0x0005e49c; body bytes: 86; decompiled */

undefined4 FUN_0005e49c(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x10);
  if (param_1 == '\0') {
    DAT_ffffd3b6 = 0x271;
    DAT_ffffd3b8 = 0;
    goto LAB_0005e50e;
  }
  if (param_1 != '\x01') {
    if (param_1 == '\x02') {
      DAT_ffffd3b8 = 2;
      goto LAB_0005e50e;
    }
    if (param_1 != '\x03') goto LAB_0005e50e;
    DAT_ffffd3b6 = 0;
  }
  DAT_ffffd3b8 = 1;
LAB_0005e50e:
  uVar1 = FUN_00003934(uVar1);
  return uVar1;
}


