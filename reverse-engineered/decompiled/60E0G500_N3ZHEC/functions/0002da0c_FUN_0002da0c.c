/* ROM address: 0x0002da0c; body bytes: 76; decompiled */

undefined4 FUN_0002da0c(void)

{
  char cVar2;
  undefined4 uVar1;
  float extraout_fr0;
  float fVar3;
  
  fVar3 = 0.0;
  uVar1 = DAT_ffffb610;
  cVar2 = FUN_00002440(DAT_ffffb610,0,0x3727c5ac);
  if (cVar2 == '\0') {
    uVar1 = 0;
    DAT_ffffbd30 = fVar3;
  }
  else {
    fVar3 = (float)FUN_00002068(DAT_ffffb608,&PTR_LAB_0006ac8c);
    uVar1 = FUN_0003ea74(DAT_ffffb614,uVar1);
    DAT_ffffbd30 = fVar3 * extraout_fr0;
  }
  return uVar1;
}


