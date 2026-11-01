/* ROM address: 0x000659aa; body bytes: 106; decompiled */

undefined4 FUN_000659aa(short param_1,char param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if ((((param_2 == '\0') || (param_2 == 'P')) || (param_2 == -0x3f)) && (DAT_ffffd7ee != '\x01')) {
    cVar1 = FUN_00060452();
    if (cVar1 == '\0') {
      uVar2 = 0;
    }
    else {
      cVar1 = FUN_00068058((int)param_1);
      if ((byte)(cVar1 + 1U) < 3) {
        FUN_00068042();
        uVar2 = 2;
      }
      else {
        FUN_00068042(3);
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}


