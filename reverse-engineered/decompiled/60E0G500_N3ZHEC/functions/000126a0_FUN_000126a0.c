/* ROM address: 0x000126a0; body bytes: 188; decompiled */

uint FUN_000126a0(void)

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
  cVar2 = FUN_00002440(DAT_ffffa760,0,0x3727c5ac);
  cVar3 = FUN_00002440(DAT_ffffa670,uVar5,uVar6);
  cVar4 = FUN_00002440(DAT_ffffca10,uVar5,uVar6);
  if (fVar7 <= 0.5) {
    if (fVar7 <= 0.45) {
      DAT_ffffa66e = 0;
    }
  }
  else {
    DAT_ffffa66e = 1;
  }
  uVar1 = (uint)DAT_ffffaada;
  if (uVar1 == 1) {
    uVar1 = (uint)cVar3;
    if (uVar1 == 0) {
      DAT_ffffa658 = 0xc1c80000;
    }
    else {
      DAT_ffffa658 = 0xc1a00000;
    }
  }
  else if ((cVar4 == '\0') && (cVar2 == '\0')) {
    DAT_ffffa658 = 0xc26a0000;
  }
  else {
    uVar1 = (uint)DAT_ffffa66e;
    if (uVar1 == 1) {
      DAT_ffffa658 = 0xc26a0000;
    }
    else {
      DAT_ffffa658 = 0xc1a00000;
    }
  }
  return uVar1;
}


