/* ROM address: 0x0001b4b0; body bytes: 606; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0001b52e) */
/* WARNING: Removing unreachable block (ram,0x0001b548) */
/* WARNING: Removing unreachable block (ram,0x0001b544) */
/* WARNING: Removing unreachable block (ram,0x0001b54a) */
/* WARNING: Removing unreachable block (ram,0x0001b55c) */

char FUN_0001b4b0(void)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  undefined4 *puVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  if (DAT_ffffad82 != '\x01') {
    DAT_ffffad78 = (float)DAT_ffffaae4;
    return DAT_ffffad82;
  }
  if (DAT_ffffa428 != '\x01') {
    DAT_ffffad78 = (float)DAT_ffffaae4;
    return DAT_ffffa428;
  }
  uVar9 = DAT_ffffab04;
  uVar10 = DAT_ffffab08;
  fVar7 = (float)FUN_00002068(DAT_ffffad8c,&PTR_LAB_00069e70);
  fVar8 = (float)FUN_00002068(DAT_ffffaaf4,&DAT_00069e7c);
  DAT_ffffaafc = (fVar8 + -1.0) * fVar7 + 1.0;
  if (DAT_ffffad80 == 0) {
    DAT_ffffab0c = 0;
  }
  else if (DAT_ffffad80 < 0x7d) {
    DAT_ffffab0c = DAT_ffffad80;
  }
  else {
    DAT_ffffab0c = 0x7d;
  }
  if (DAT_ffffad81 == 0) {
    DAT_ffffab0d = 0;
  }
  else if (DAT_ffffad81 < 0x7d) {
    DAT_ffffab0d = DAT_ffffad81;
  }
  else {
    DAT_ffffab0d = 0x7d;
  }
  cVar2 = -0x6a;
  uVar5 = 0x95;
  puVar6 = &DAT_ffffad6c;
  do {
    cVar2 = cVar2 + -1;
    puVar6 = puVar6 + -1;
    *puVar6 = (&DAT_ffffab10)[uVar5 & 0xff];
    uVar5 = uVar5 + 0xff;
  } while (cVar2 != '\0');
  DAT_ffffab10 = DAT_ffffaafc;
  DAT_ffffab04 = (&DAT_ffffab10)[DAT_ffffab0c];
  DAT_ffffab08 = (&DAT_ffffab10)[DAT_ffffab0d];
  if (DAT_ffffab0c < DAT_ffffab0d) {
    cVar2 = FUN_00002440(uVar10,DAT_ffffad78,0x3727c5ac);
    if (DAT_ffffab04 < DAT_ffffab08) {
      if (cVar2 == '\0') {
        DAT_ffffab0e = '\0';
      }
    }
    else {
      DAT_ffffab0e = '\x01';
    }
  }
  else {
    cVar2 = FUN_00002440(uVar9,DAT_ffffad78,0x3727c5ac);
    if (DAT_ffffab04 < DAT_ffffab08) {
      if (cVar2 == '\0') {
        DAT_ffffab0e = '\x01';
      }
    }
    else {
      DAT_ffffab0e = '\0';
    }
  }
  if (DAT_ffffab0c == DAT_ffffab0d) {
    DAT_ffffab0f = 0;
    bVar1 = false;
    goto LAB_0001b72e;
  }
  bVar3 = FUN_00002478((int)(char)DAT_ffffab0c,1);
  if (0x95 < bVar3) {
    bVar3 = 0x96;
  }
  bVar4 = FUN_00002478((int)(char)DAT_ffffab0d,1);
  if (0x95 < bVar4) {
    bVar4 = 0x96;
  }
  if (DAT_ffffab0e == '\x01') {
    if (DAT_ffffab04 < (&DAT_ffffab10)[bVar3]) {
LAB_0001b710:
      DAT_ffffab0f = 1;
      bVar1 = true;
      goto LAB_0001b72e;
    }
    if (DAT_ffffad78 < DAT_ffffab04) {
      DAT_ffffab0f = 0;
      bVar1 = false;
      goto LAB_0001b72e;
    }
  }
  else {
    if ((&DAT_ffffab10)[bVar4] <= DAT_ffffab08) goto LAB_0001b710;
    if (DAT_ffffab08 <= DAT_ffffad78) {
      DAT_ffffab0f = 0;
      bVar1 = false;
      goto LAB_0001b72e;
    }
  }
  DAT_ffffab0f = 1;
  bVar1 = true;
LAB_0001b72e:
  if (bVar1) {
    DAT_ffffab00 = DAT_ffffad78;
    cVar2 = '\x01';
  }
  else {
    cVar2 = DAT_ffffab0e;
    DAT_ffffab00 = DAT_ffffab08;
    if (DAT_ffffab0e == '\x01') {
      DAT_ffffab00 = DAT_ffffab04;
    }
  }
  DAT_ffffad78 = (float)DAT_ffffaae4;
  return cVar2;
}


