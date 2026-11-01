/* ROM address: 0x00068bd0; body bytes: 136; decompiled */

undefined4 FUN_00068bd0(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_1 == '\0') {
    cVar1 = FUN_00068e9c();
    if (cVar1 == '\0') {
      uVar2 = FUN_00068cec();
    }
  }
  else if (param_1 == '\x10') {
    cVar1 = FUN_00068eb6();
    if (cVar1 == '\0') {
      FUN_00068d42();
    }
  }
  else if (param_1 == ' ') {
    cVar1 = FUN_00068ed0();
    if ((cVar1 == '\0') && (FUN_00068dc4(), DAT_ffffde22 <= DAT_ffffde24)) {
      FUN_000693fc(5);
      uVar2 = 0;
    }
  }
  else if (param_1 == '0') {
    cVar1 = FUN_00068f08();
    if (cVar1 == '\0') {
      FUN_00068e2c();
    }
  }
  return uVar2;
}


