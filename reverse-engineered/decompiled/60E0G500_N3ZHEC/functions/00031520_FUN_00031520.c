/* ROM address: 0x00031520; body bytes: 346; decompiled */

void FUN_00031520(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  
  fVar2 = DAT_ffffbe80;
  fVar1 = DAT_ffffbe7c;
  fVar4 = DAT_ffffbe78;
  fVar5 = DAT_ffffbe58;
  fVar6 = DAT_ffffbe54;
  fVar3 = DAT_ffffbe50;
  fVar8 = DAT_ffffbeb0;
  uVar9 = DAT_ffffb5b8;
  DAT_ffffbf84 = (float)FUN_00002068(DAT_ffffb5b8,&DAT_0006b088);
  fVar10 = 6e+07;
  fVar7 = fVar3 * fVar4 * 6e+07;
  fVar4 = fVar7;
  fVar3 = (float)FUN_0003ea74(0x4c64e1c0,uVar9);
  fVar4 = (float)FUN_0003ea74(fVar3 * (DAT_ffffbf84 / 360.0),fVar4);
  DAT_ffffbf34 = fVar4 * 369.472;
  fVar4 = fVar5 * fVar2 * fVar10;
  fVar5 = (float)FUN_0003ea74(fVar10,uVar9);
  fVar5 = (float)FUN_0003ea74(fVar5 * (DAT_ffffbf84 / 360.0),fVar4);
  DAT_ffffbf58 = fVar5 * 475.93;
  fVar5 = (float)FUN_0003ea74(fVar10,uVar9);
  fVar5 = (float)FUN_0003ea74((fVar5 - 608.0) - DAT_ffffbeac,fVar7);
  DAT_ffffbf44 = fVar5 * 369.472;
  fVar5 = fVar6 * fVar1 * fVar10;
  fVar6 = (float)FUN_0003ea74(fVar10,uVar9);
  fVar6 = (float)FUN_0003ea74((fVar6 - 608.0) - fVar8,fVar5);
  DAT_ffffbf48 = fVar6 * 475.93;
  fVar6 = (float)FUN_0003ea74(fVar10,uVar9);
  fVar6 = (float)FUN_0003ea74((fVar6 - 608.0) - fVar8,fVar4);
  DAT_ffffbf4c = fVar6 * 475.93;
  DAT_ffffbf50 = FUN_0003ea74(0x493e8ed3,fVar5);
  DAT_ffffbf54 = FUN_0003ea74(0x48fafa8d,fVar4);
  return;
}


