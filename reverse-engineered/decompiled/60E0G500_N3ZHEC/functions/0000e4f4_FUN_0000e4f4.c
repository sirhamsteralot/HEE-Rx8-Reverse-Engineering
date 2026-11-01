/* ROM address: 0x0000e4f4; body bytes: 108; decompiled */

void FUN_0000e4f4(void)

{
  undefined **ppuVar1;
  undefined4 uVar2;
  
  if (DAT_ffffb5aa == '\x01') {
    DAT_ffffa460 = FUN_000020ac(&PTR_PTR_00069700);
  }
  else if (DAT_ffffb5a4 == '\x01') {
    uVar2 = FUN_00002500(0x3f800000,0,(int)DAT_ffffa461);
    DAT_ffffa460 = FUN_00002120(DAT_ffffb5b8,uVar2,&PTR_DAT_00069738);
  }
  else {
    if (DAT_ffffcabc == '\x01') {
      ppuVar1 = &PTR_PTR_0006970c;
    }
    else {
      ppuVar1 = &PTR_PTR_00069718;
    }
    DAT_ffffa460 = FUN_000020ac(DAT_ffffb5b8,ppuVar1);
  }
  return;
}


