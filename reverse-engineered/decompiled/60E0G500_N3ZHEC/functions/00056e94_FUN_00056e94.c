/* ROM address: 0x00056e94; body bytes: 90; decompiled */

undefined4 FUN_00056e94(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x10);
  DAT_ffffd21c = 1;
  if (param_1 == '\0') {
    DAT_ffffd21e = 0xffff;
    DAT_ffffd220 = 0;
    goto LAB_00056ee0;
  }
  if (param_1 != '\x01') {
    if (param_1 == '\x02') {
      DAT_ffffd220 = 2;
      goto LAB_00056ee0;
    }
    if (param_1 != '\x03') goto LAB_00056ee0;
    DAT_ffffd21e = 0;
  }
  DAT_ffffd220 = 1;
LAB_00056ee0:
  uVar1 = FUN_00003934(uVar1);
  return uVar1;
}


