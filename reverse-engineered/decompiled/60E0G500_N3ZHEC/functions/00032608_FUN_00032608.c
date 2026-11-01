/* ROM address: 0x00032608; body bytes: 332; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00032770) */
/* WARNING: Removing unreachable block (ram,0x000326a0) */

void FUN_00032608(void)

{
  char cVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  cVar1 = DAT_ffffa41c;
  fVar5 = DAT_ffffae54;
  fVar6 = DAT_ffffc12c;
  fVar7 = DAT_ffffaa10;
  fVar3 = (float)FUN_00002068(DAT_ffffaa10,&PTR_DAT_0006b194);
  fVar4 = (float)FUN_00002068(DAT_ffffad8c,&PTR_LAB_0006b1a8);
  DAT_ffffbfe0 = fVar3 + fVar4;
  if (fVar6 <= DAT_ffffbfe0) {
    if (fVar6 <= DAT_ffffbfe0 - 0.05) {
      DAT_ffffbfe5 = '\0';
    }
  }
  else {
    DAT_ffffbfe5 = '\x01';
  }
  if ((DAT_ffffbfe8 == '\x01') && (cVar1 == '\0')) {
    DAT_ffffbfe4 = '\x06';
    DAT_ffffbfe9 = '\x01';
  }
  else if (DAT_ffffbfe4 != '\0') {
    DAT_ffffbfe4 = DAT_ffffbfe4 + -1;
  }
  if ((DAT_ffffd2aa == '\x01') ||
     ((((((DAT_ffffc656 == '\0' && (DAT_ffffbfe5 == '\0')) && (DAT_ffffbfd8 != 0)) &&
        ((fVar7 <= 35.0 || (DAT_ffffaaf9 == '\0')))) &&
       ((-15.0 <= fVar5 && ((fVar5 <= 40.0 && (cVar1 == '\0')))))) &&
      ((DAT_ffffbfe9 == '\x01' && (DAT_ffffbfe4 == '\0')))))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  DAT_ffffbfd4 = FUN_0005d644(uVar2);
  DAT_ffffbfe8 = cVar1;
  return;
}


