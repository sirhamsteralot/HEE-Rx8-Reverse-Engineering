/* ROM address: 0x000690ce; body bytes: 66; decompiled */

void FUN_000690ce(void)

{
  int iVar1;
  
  FUN_000693fc(3);
  if (DAT_ffffde32 == '\x01') {
    FUN_0006936a(1,0xf96);
    DAT_ffffde31 = DAT_ffffde31 & 0xef;
    iVar1 = 0x7f;
  }
  else {
    FUN_000693fc(1);
    FUN_000693fc(0);
    FUN_000690b4();
    iVar1 = (int)DAT_ffffde1c;
  }
  thunk_FUN_000551da(iVar1);
  return;
}


