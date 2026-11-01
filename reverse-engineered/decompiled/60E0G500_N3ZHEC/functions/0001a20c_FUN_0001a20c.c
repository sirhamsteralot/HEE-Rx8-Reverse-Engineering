/* ROM address: 0x0001a20c; body bytes: 546; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0001a428) */
/* WARNING: Removing unreachable block (ram,0x0001a490) */
/* WARNING: Removing unreachable block (ram,0x0001a430) */
/* WARNING: Removing unreachable block (ram,0x0001a49c) */

void FUN_0001a20c(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  float arg2;
  
  arg2 = 100.0;
  fVar2 = DAT_ffffaa38;
  uVar4 = DAT_ffffaa10;
  fVar1 = (float)FUN_0003ea74(DAT_ffffaa30,0x414b3333);
  fVar3 = 0.0;
  DAT_ffffaa38 = rx8_clamp_float(fVar1 * arg2 - 0.0,0.0,arg2);
  fVar1 = (float)FUN_0003ea74(DAT_ffffaa34,0x414b3333);
  DAT_ffffaa3c = rx8_clamp_float(fVar1 * arg2 - 0.0,fVar3,arg2);
  fVar1 = DAT_ffffaa38 - DAT_ffffaa50;
  DAT_ffffaa68 = (float)FUN_00002068(uVar4,&PTR_LAB_00069e34);
  DAT_ffffaa70 = DAT_ffffaa38 - fVar2;
  if ((((fVar1 <= 1.7) || (DAT_ffffaa38 < DAT_ffffaa68)) || (DAT_ffffa428 == '\0')) ||
     (((DAT_ffffb5aa == '\0' || (0.0 < DAT_ffffbc1c)) || (DAT_ffffc68e == '\x01')))) {
    DAT_ffffaa5f = '\0';
  }
  else if (12.0 <= DAT_ffffaa70) {
    DAT_ffffaa5f = '\x01';
  }
  if (DAT_ffffaa5f == '\x01') {
    fVar3 = (float)FUN_00002068(uVar4,&PTR_LAB_00069e20);
  }
  DAT_ffffaa48 = fVar3;
  DAT_ffffaa6c = (float)FUN_00002068(uVar4,&PTR_LAB_00069e40);
  fVar1 = 1.0 - DAT_ffffaa48;
  fVar3 = 1e-05;
  fVar2 = rx8_first_order_filter(DAT_ffffaa38,DAT_ffffaa50,fVar1,1e-05);
  DAT_ffffaa50 = rx8_min_float(fVar2,DAT_ffffaa6c);
  fVar2 = rx8_first_order_filter(DAT_ffffaa3c,DAT_ffffaa54,fVar1,fVar3);
  DAT_ffffaa54 = rx8_min_float(fVar2,DAT_ffffaa6c);
  if (DAT_ffffaa38 < 50.0) {
    if (DAT_ffffaa38 < 45.0) {
      DAT_ffffaa7b = 0;
    }
  }
  else {
    DAT_ffffaa7b = 1;
  }
  if (DAT_ffffccdb == '\x01') {
    if (DAT_ffffccdc == '\x01') {
      DAT_ffffaa40 = 15.0;
    }
    else {
      DAT_ffffaa40 = rx8_min_float(DAT_ffffaa54,13.5);
    }
  }
  else if (DAT_ffffccdc == '\x01') {
    DAT_ffffaa40 = rx8_min_float(DAT_ffffaa50,13.5);
  }
  else {
    fVar2 = rx8_max_float(DAT_ffffaa50,DAT_ffffbd64);
    fVar2 = rx8_min_float(fVar2,DAT_ffffc090);
    if (DAT_ffffa998 == '\x01') {
      fVar3 = 13.5;
    }
    else {
      fVar3 = 100.0;
    }
    DAT_ffffaa40 = rx8_min_float(fVar2,fVar3);
  }
  DAT_ffffaa44 = DAT_ffffaa40 - DAT_ffffaa64;
  DAT_ffffaa64 = DAT_ffffaa60;
  DAT_ffffaa60 = DAT_ffffaa40;
  return;
}


