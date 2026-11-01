/* ROM address: 0x0005ad4a; body bytes: 66; decompiled */

int FUN_0005ad4a(undefined4 *param_1)

{
  char cVar2;
  undefined4 uVar1;
  
  cVar2 = FUN_0003eaa4(&DAT_ffff9134,0);
  uVar1 = FUN_0003eb24(&DAT_ffff912c,0);
  *param_1 = uVar1;
  if ((cVar2 == '\0') || (DAT_ffffc6ac == '\x01')) {
    DAT_ffffd318 = '\x01';
  }
  return (int)DAT_ffffd318;
}


