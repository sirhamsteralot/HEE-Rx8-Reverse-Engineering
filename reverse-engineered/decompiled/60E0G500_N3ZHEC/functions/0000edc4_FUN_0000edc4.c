/* ROM address: 0x0000edc4; body bytes: 134; decompiled */

void FUN_0000edc4(char param_1)

{
  if (DAT_ffffa464 == '\x01') {
    DAT_ffffa444 = 1;
    DAT_ffffa445 = 1;
    goto LAB_0000ee36;
  }
  if (DAT_ffffa465 == '\x01') {
    if (DAT_ffffa4a3 == '\0') {
      if ((param_1 != '\x06') && (param_1 != '\x12')) {
        DAT_ffffa444 = 0;
        DAT_ffffa445 = 1;
        goto LAB_0000ee36;
      }
    }
    else {
      if (DAT_ffffa4a2 != '\x01') goto LAB_0000ee36;
      if ((param_1 != '\0') && (param_1 != '\f')) {
        DAT_ffffa444 = 0;
        DAT_ffffa445 = 1;
        goto LAB_0000ee36;
      }
    }
    DAT_ffffa444 = 1;
  }
  else {
    DAT_ffffa444 = 0;
  }
  DAT_ffffa445 = 0;
LAB_0000ee36:
  DAT_ffffa4a2 = DAT_ffffa464;
  DAT_ffffa4a3 = DAT_ffffa465;
  FUN_0000e2d4();
  return;
}


