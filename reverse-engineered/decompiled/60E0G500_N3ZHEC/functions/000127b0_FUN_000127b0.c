/* ROM address: 0x000127b0; body bytes: 188; decompiled */

uint FUN_000127b0(void)

{
  char cVar2;
  char cVar3;
  char cVar4;
  uint uVar1;
  undefined4 uVar5;
  undefined4 uVar6;
  float fVar7;
  
  uVar5 = 0;
  uVar6 = 0x3727c5ac;
  fVar7 = DAT_ffffc12c;
  cVar2 = FUN_00002440(DAT_ffffa764,0,0x3727c5ac);
  cVar3 = FUN_00002440(DAT_ffffa674,uVar5,uVar6);
  cVar4 = FUN_00002440(DAT_ffffca14,uVar5,uVar6);
  if (fVar7 <= 0.5) {
    if (fVar7 <= 0.45) {
      DAT_ffffa66f = 0;
    }
  }
  else {
    DAT_ffffa66f = 1;
  }
  uVar1 = (uint)DAT_ffffaada;
  if (uVar1 == 1) {
    uVar1 = (uint)cVar3;
    if (uVar1 == 0) {
      DAT_ffffa668 = 0xc1c80000;
    }
    else {
      DAT_ffffa668 = 0xc1a00000;
    }
  }
  else if ((cVar4 == '\0') && (cVar2 == '\0')) {
    DAT_ffffa668 = 0xc28a6666;
  }
  else {
    uVar1 = (uint)DAT_ffffa66f;
    if (uVar1 == 1) {
      DAT_ffffa668 = 0xc28a6666;
    }
    else {
      DAT_ffffa668 = 0xc1a00000;
    }
  }
  return uVar1;
}


