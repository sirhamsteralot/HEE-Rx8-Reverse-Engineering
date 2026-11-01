/* ROM address: 0x000207f8; body bytes: 398; decompiled */

undefined4 * FUN_000207f8(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  undefined4 *puVar5;
  float fVar6;
  float fVar7;
  
  cVar4 = DAT_ffffb1c6;
  cVar3 = DAT_ffffb1c5;
  cVar2 = DAT_ffffb1c3;
  cVar1 = DAT_ffffaae0;
  fVar6 = -43.0;
  puVar5 = (undefined4 *)(uint)DAT_ffffb1c2;
  fVar7 = DAT_ffffaa10;
  if (((DAT_ffffb1b0 == 0) || (DAT_ffffb1c2 != 0)) &&
     ((DAT_ffffb245 != '\0' || (DAT_ffffaae0 != '\x01')))) {
    if (DAT_ffffb1b0 == 0) {
      if (puVar5 == (undefined4 *)0x0) {
        DAT_ffffb1b2 = 1;
      }
      else if ((DAT_ffffb246 == '\0') && (DAT_ffffb1c5 == '\x01')) {
        DAT_ffffb1b2 = FUN_000020c4(DAT_ffffaa10,&PTR_DAT_0006a480);
      }
      else if ((DAT_ffffb247 == '\0') && (DAT_ffffb1c6 == '\x01')) {
        DAT_ffffb1b2 = FUN_000020c4(DAT_ffffaa10,&PTR_DAT_0006a48c);
      }
      else if (DAT_ffffb1b2 != 0) {
        DAT_ffffb1b2 = DAT_ffffb1b2 + -1;
      }
    }
    else if ((puVar5 == (undefined4 *)0x1) && (DAT_ffffb1b2 != 0)) {
      DAT_ffffb1b2 = DAT_ffffb1b2 + -1;
    }
  }
  else {
    DAT_ffffb1b2 = 0;
  }
  if (fVar7 < -40.0) {
    if (fVar7 < fVar6) {
      DAT_ffffb23f = 0;
    }
  }
  else {
    DAT_ffffb23f = 1;
  }
  if (((((puVar5 == (undefined4 *)0x1) && (DAT_ffffb1b2 != 0)) || (DAT_ffffb1c9 == '\0')) ||
      (puVar5 = &DAT_ffffc6b4, 1000.0 < DAT_ffffc6b4)) ||
     ((DAT_ffffb245 == '\0' && (puVar5 = (undefined4 *)0x1, cVar1 == '\x01')))) {
    DAT_ffffb1b0 = 8;
  }
  else {
    puVar5 = (undefined4 *)(int)cVar2;
    if (((puVar5 == (undefined4 *)0x0) &&
        (puVar5 = (undefined4 *)(uint)DAT_ffffb23f, puVar5 == (undefined4 *)0x1)) &&
       (DAT_ffffb1b0 != 0)) {
      DAT_ffffb1b0 = DAT_ffffb1b0 + -1;
    }
  }
  DAT_ffffb245 = cVar1;
  DAT_ffffb246 = cVar3;
  DAT_ffffb247 = cVar4;
  return puVar5;
}


