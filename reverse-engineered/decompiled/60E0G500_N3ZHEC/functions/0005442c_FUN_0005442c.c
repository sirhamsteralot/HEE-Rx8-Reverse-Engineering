/* ROM address: 0x0005442c; body bytes: 66; decompiled */

void FUN_0005442c(void)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_0003eaa4(&DAT_ffff9000,0);
  if (((cVar1 == '\0') && (cVar1 = FUN_0003eaa4(&DAT_ffff8688,0), cVar1 == '\0')) ||
     (DAT_ffffd201 == '\x01')) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  FUN_0003ebc0(&DAT_ffff9002,uVar2);
  return;
}


