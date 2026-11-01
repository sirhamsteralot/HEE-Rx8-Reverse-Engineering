/* ROM address: 0x000516f8; body bytes: 190; decompiled */

undefined4 * FUN_000516f8(void)

{
  char cVar2;
  char cVar3;
  char cVar4;
  undefined4 *puVar1;
  float fVar5;
  undefined4 uVar6;
  float fVar7;
  float fVar8;
  
  fVar8 = 0.0;
  fVar5 = (float)FUN_000024c0(0x42c80000,0,(int)DAT_ffffd0e0);
  fVar7 = 1000.0;
  fVar5 = fVar5 / 1000.0;
  uVar6 = FUN_0003eb72(fVar8,&DAT_ffff86d0);
  cVar2 = FUN_00002440(uVar6,fVar8,0x36b33333);
  cVar3 = FUN_00002440(DAT_ffffd0f0,fVar8,0x36b33333);
  cVar4 = FUN_00002440(fVar5,fVar8,0x3727c5ac);
  if (DAT_ffffd201 == '\x01') {
    puVar1 = (undefined4 *)0x1;
    DAT_ffffd0d4 = fVar8;
  }
  else {
    puVar1 = (undefined4 *)(uint)DAT_ffffd0e4;
    if (((puVar1 == (undefined4 *)0x1) &&
        (puVar1 = (undefined4 *)(int)cVar3, puVar1 == (undefined4 *)0x0)) && (cVar2 != '\0')) {
      if (cVar4 == '\0') {
        puVar1 = &DAT_0005189c;
        DAT_ffffd0d4 = 0.35999998;
      }
      else {
        DAT_ffffd0d4 = ((DAT_ffffd01c - DAT_ffffd024) * fVar7) / fVar5;
      }
    }
  }
  DAT_ffffd0f0 = uVar6;
  return puVar1;
}


