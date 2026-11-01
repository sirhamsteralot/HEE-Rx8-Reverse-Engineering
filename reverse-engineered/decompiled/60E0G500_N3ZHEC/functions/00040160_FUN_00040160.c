/* ROM address: 0x00040160; body bytes: 76; decompiled */

void FUN_00040160(void)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  
  uVar2 = DAT_ffffaa88;
  fVar1 = (float)FUN_0003eb72(0,&DAT_ffff8114);
  DAT_ffffc754 = (float)FUN_00002068(uVar2,&DAT_0006a1d4);
  DAT_ffffc758 = (float)FUN_00002068(uVar2,&DAT_0006a1e8);
  fVar3 = DAT_ffffc758 + fVar1;
  FUN_0003ec20(fVar1 - DAT_ffffc754,&DAT_ffff8740);
  FUN_0003ec20(fVar3,&DAT_ffff8748);
  return;
}


