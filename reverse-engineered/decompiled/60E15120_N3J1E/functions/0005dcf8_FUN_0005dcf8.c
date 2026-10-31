/* ROM address: 0x0005dcf8; body bytes: 86; decompiled */

undefined4 FUN_0005dcf8(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if (param_1 == '\0') {
    DAT_ffffd37a = 0x271;
    DAT_ffffd37c = 0;
    goto LAB_0005dd6a;
  }
  if (param_1 != '\x01') {
    if (param_1 == '\x02') {
      DAT_ffffd37c = 2;
      goto LAB_0005dd6a;
    }
    if (param_1 != '\x03') goto LAB_0005dd6a;
    DAT_ffffd37a = 0;
  }
  DAT_ffffd37c = 1;
LAB_0005dd6a:
  uVar1 = ref_setSR(uVar1);
  return uVar1;
}


