/* ROM address: 0x0004746c; body bytes: 80; decompiled */

void FUN_0004746c(void)

{
  undefined4 uVar1;
  char cVar2;
  
  uVar1 = FUN_0003eae4(&DAT_ffff8774,0);
  cVar2 = FUN_0003eaa4(&DAT_ffff8788,1);
  if (cVar2 == '\x01') {
    FUN_0003ebc0(&DAT_ffff8770,0);
    uVar1 = 0;
  }
  else {
    cVar2 = FUN_0003eaa4(&DAT_ffff8772,0);
    if (cVar2 == '\x01') {
      uVar1 = FUN_00002460(uVar1,1);
    }
  }
  FUN_0003ebd0(&DAT_ffff8774,uVar1);
  return;
}


