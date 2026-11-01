/* ROM address: 0x0005b7bc; body bytes: 62; decompiled */

uint FUN_0005b7bc(byte param_1)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = (uint)param_1;
  bVar1 = param_1;
  if (uVar2 != 1) {
    if (uVar2 == 2) {
      uVar2 = (uint)DAT_ffffd31c;
      if (uVar2 == 1) {
        uVar2 = FUN_00009efe();
        return uVar2;
      }
      DAT_ffffd31c = 0;
      bVar1 = DAT_ffffd31c;
    }
    else {
      DAT_ffffd31c = 0;
      bVar1 = DAT_ffffd31c;
    }
  }
  DAT_ffffd31c = bVar1;
  return uVar2;
}


