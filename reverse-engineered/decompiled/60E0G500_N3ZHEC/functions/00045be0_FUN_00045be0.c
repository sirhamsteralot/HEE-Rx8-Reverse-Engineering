/* ROM address: 0x00045be0; body bytes: 98; decompiled */

uint FUN_00045be0(void)

{
  char cVar2;
  uint uVar1;
  undefined4 uVar3;
  byte bVar4;
  
  if (DAT_ffffcc09 == '\x01') {
    cVar2 = FUN_00065e34(0);
    if (cVar2 == '\0') {
      uVar3 = 4;
    }
    else {
      uVar3 = 2;
    }
    uVar1 = FUN_000604e0(0,uVar3);
  }
  else {
    uVar1 = (uint)DAT_ffffcc0a;
    if (uVar1 == 1) {
      bVar4 = (DAT_ffffcc08 & 1) != 0;
      if ((DAT_ffffcc08 & 2) != 0) {
        bVar4 = bVar4 | 2;
      }
      uVar1 = FUN_000604e0(0,1,bVar4);
    }
  }
  return uVar1;
}


