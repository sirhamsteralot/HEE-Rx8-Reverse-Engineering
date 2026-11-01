/* ROM address: 0x0003b326; body bytes: 184; decompiled */

undefined4 FUN_0003b326(void)

{
  char cVar2;
  undefined4 uVar1;
  undefined4 extraout_r0;
  float extraout_fr0;
  float arg0;
  
  if (DAT_ffffd2aa == '\x01') {
    DAT_ffffc5a4 = 1.1;
    uVar1 = 1;
  }
  else {
    arg0 = DAT_ffffc5a4;
    if (DAT_ffffbfd4 == '\x01') {
      cVar2 = FUN_00002440(DAT_ffffc5a8,0,0x3727c5ac);
      DAT_ffffc5bc = (float)FUN_00002068(DAT_ffffad8c,&DAT_0006b980);
      uVar1 = FUN_000020dc(DAT_ffffb5b8,DAT_ffffc12c,&PTR_DAT_0006b994);
      DAT_ffffc5c0 = extraout_fr0;
      if (cVar2 == '\0') {
        DAT_ffffc5a4 = 1.0;
        goto LAB_0003b3e8;
      }
      arg0 = ((extraout_fr0 + -1.0) * DAT_ffffc5bc * 0.01 + 1.0) / DAT_ffffc5a8;
    }
    DAT_ffffc5a4 = rx8_max_float(arg0,0.7656);
    uVar1 = extraout_r0;
  }
LAB_0003b3e8:
  DAT_ffffc5b5 = DAT_ffffc5a4 <= DAT_ffffaae4;
  DAT_ffffc5b4 = DAT_ffffc5a4 > DAT_ffffaae4;
  return uVar1;
}


