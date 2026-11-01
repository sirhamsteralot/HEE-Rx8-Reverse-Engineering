/* ROM address: 0x0004b938; body bytes: 90; decompiled */

void FUN_0004b938(void)

{
  float fVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (DAT_ffffa444 == DAT_ffffa445) {
    DAT_ffffce34 = 0.0;
  }
  else {
    DAT_ffffce38 = (float)FUN_00002068(DAT_ffffc12c,&PTR_DAT_0006be50);
    DAT_ffffce3c = (float)FUN_00002068(DAT_ffffb5b8,&DAT_0006be64);
    fVar1 = (float)FUN_00002500(0x3c23d70a,uVar2,100);
    DAT_ffffce34 = DAT_ffffce38 * DAT_ffffce3c * fVar1;
  }
  return;
}


