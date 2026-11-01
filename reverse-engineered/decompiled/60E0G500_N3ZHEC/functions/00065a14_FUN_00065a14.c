/* ROM address: 0x00065a14; body bytes: 68; decompiled */

undefined4 FUN_00065a14(short param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_0006043c();
  if (cVar1 == '\0') {
    uVar2 = 0;
  }
  else {
    cVar1 = FUN_00068058((int)param_1);
    if ((byte)(cVar1 + 1U) < 4) {
      FUN_00068042();
      uVar2 = 2;
    }
    else {
      FUN_00068042(4);
      uVar2 = 1;
    }
  }
  return uVar2;
}


