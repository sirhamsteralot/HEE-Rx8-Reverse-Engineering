/* ROM address: 0x0004b6bc; body bytes: 194; decompiled */

uint FUN_0004b6bc(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  float arg1;
  undefined4 uVar4;
  
  cVar2 = DAT_ffffa445;
  cVar1 = DAT_ffffa444;
  uVar4 = DAT_ffffb5b8;
  DAT_ffffce30 = FUN_000020ac(DAT_ffffb5b8,&PTR_PTR_0006be78);
  arg1 = 0.0;
  if (((DAT_ffffa428 == '\0') || (cVar1 == '\x01')) || (cVar2 == '\x01')) {
    DAT_ffffce20 = 0.0;
    DAT_ffffce25 = 0;
  }
  else if (((DAT_ffffce33 == '\0') || ((DAT_ffffce2c != 0 && (DAT_ffffce2e != 0)))) ||
          (DAT_ffffce30 < DAT_ffffce24)) {
    DAT_ffffce28 = (float)FUN_00002068(uVar4,&DAT_0006be84);
    DAT_ffffce20 = rx8_max_float(DAT_ffffce20 - DAT_ffffce28,arg1);
  }
  uVar3 = (uint)DAT_ffffce25;
  if (uVar3 == 1) {
    uVar3 = FUN_00002478((int)(char)DAT_ffffce24,1);
    DAT_ffffce24 = (byte)uVar3;
  }
  else {
    DAT_ffffce24 = 0;
  }
  return uVar3;
}


