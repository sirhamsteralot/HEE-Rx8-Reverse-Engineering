/* ROM address: 0x0005e9d6; body bytes: 60; decompiled */

undefined4 FUN_0005e9d6(void)

{
  undefined4 uVar1;
  char cVar2;
  
  uVar1 = FUN_00003920(0x10);
  cVar2 = FUN_0005ea7c();
  if ((cVar2 == '\0') && (DAT_ffffd3c3 == '\x01')) {
    FUN_00059b34();
    DAT_ffffd3c3 = '\0';
  }
  uVar1 = FUN_00003934(uVar1);
  return uVar1;
}


