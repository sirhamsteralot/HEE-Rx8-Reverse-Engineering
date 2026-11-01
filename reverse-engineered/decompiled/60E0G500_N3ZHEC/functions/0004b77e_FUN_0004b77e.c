/* ROM address: 0x0004b77e; body bytes: 282; decompiled */

uint FUN_0004b77e(void)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  undefined *puVar4;
  float fVar5;
  undefined4 uVar6;
  float extraout_fr0;
  
  bVar2 = DAT_ffffa445;
  cVar1 = DAT_ffffa444;
  if ((DAT_ffffce31 == '\0') && (DAT_ffffa444 == '\x01')) {
    DAT_ffffce2c = 0x3e;
    DAT_ffffce33 = 1;
  }
  else if (DAT_ffffce2c != 0) {
    DAT_ffffce2c = DAT_ffffce2c + -1;
  }
  if ((DAT_ffffce32 == '\0') && (DAT_ffffa445 == 1)) {
    DAT_ffffce2e = 0x3e;
    DAT_ffffce33 = 1;
  }
  else if (DAT_ffffce2e != 0) {
    DAT_ffffce2e = DAT_ffffce2e + -1;
  }
  uVar3 = (uint)DAT_ffffa428;
  if ((((uVar3 == 1) && (DAT_ffffa444 == '\0')) && (uVar3 = (uint)DAT_ffffa445, uVar3 == 0)) &&
     ((uVar3 = (uint)DAT_ffffce33, uVar3 == 1 &&
      ((DAT_ffffce2c == 0 || (uVar3 = (uint)DAT_ffffce2e, uVar3 == 0)))))) {
    uVar6 = DAT_ffffb5b8;
    DAT_ffffce30 = FUN_000020ac(DAT_ffffb5b8,&PTR_PTR_0006be78);
    uVar3 = (uint)DAT_ffffce30;
    if (DAT_ffffce24 <= uVar3) {
      if (DAT_ffffaada == '\0') {
        puVar4 = &DAT_0006beac;
      }
      else {
        puVar4 = &DAT_0006bec8;
      }
      fVar5 = (float)FUN_000020dc(DAT_ffffaa10,uVar6,puVar4);
      uVar6 = FUN_000024c0(0x42800000,0,(int)DAT_ffffc1d8);
      uVar3 = FUN_00002068(uVar6,&DAT_0006be98);
      DAT_ffffce20 = fVar5 * extraout_fr0;
      DAT_ffffce25 = 1;
    }
  }
  DAT_ffffce31 = cVar1;
  DAT_ffffce32 = bVar2;
  return uVar3;
}


