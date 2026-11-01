/* ROM address: 0x00015ff0; body bytes: 70; decompiled */

void FUN_00015ff0(void)

{
  short sVar1;
  
  if (DAT_ffffb5a4 == '\x01') {
    DAT_ffffa89c = FUN_0003eb72(0,&DAT_ffff8040);
  }
  else {
    if (DAT_ffffb5ac == '\0') {
      sVar1 = -0x7fc0;
    }
    else {
      sVar1 = -0x7fb8;
    }
    DAT_ffffa89c = FUN_0003eb72(0,(int)sVar1);
  }
  return;
}


