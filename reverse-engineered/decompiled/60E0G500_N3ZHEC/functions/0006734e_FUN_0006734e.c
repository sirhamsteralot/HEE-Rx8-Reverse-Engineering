/* ROM address: 0x0006734e; body bytes: 78; decompiled */

undefined4 FUN_0006734e(uint param_1)

{
  int iVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar3 = 1;
  do {
    bVar2 = FUN_00060c66(iVar4);
    iVar1 = iVar4 + (param_1 & 0xffff) * 2;
    iVar4 = iVar4 + 1;
    if (((&DAT_0007e734)[iVar1] & bVar2) != 0) {
      uVar3 = 0;
    }
  } while (iVar4 < 2);
  return uVar3;
}


