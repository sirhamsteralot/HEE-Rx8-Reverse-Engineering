/* ROM address: 0x0004565c; body bytes: 106; decompiled */

uint FUN_0004565c(void)

{
  char cVar2;
  uint uVar1;
  undefined4 uVar3;
  byte bVar4;
  
  DAT_ffffbb09 = DAT_ffffbb08;
  if (DAT_ffffcbdd == '\x01') {
    cVar2 = FUN_00065e34(1);
    if (cVar2 == '\0') {
      uVar3 = 4;
    }
    else {
      uVar3 = 2;
    }
    uVar1 = FUN_000604e0(1,uVar3,0);
  }
  else {
    uVar1 = (uint)DAT_ffffcbde;
    if (uVar1 == 1) {
      bVar4 = (DAT_ffffcbdc & 1) != 0;
      if ((DAT_ffffcbdc & 2) != 0) {
        bVar4 = bVar4 | 2;
      }
      uVar1 = FUN_000604e0(1,1,bVar4);
    }
  }
  return uVar1;
}


