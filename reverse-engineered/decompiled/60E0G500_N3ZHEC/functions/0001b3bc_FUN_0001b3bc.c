/* ROM address: 0x0001b3bc; body bytes: 170; decompiled */

void FUN_0001b3bc(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = 1.0;
  if (DAT_ffffa428 == '\0') {
    DAT_ffffaae4 = 1.0;
    DAT_ffffaae8 = 1.0;
    DAT_ffffaaec = 1.0;
    DAT_ffffaafc = 0x3f800000;
    DAT_ffffab00 = 1.0;
    DAT_ffffab04 = 0x3f800000;
    DAT_ffffab08 = 0x3f800000;
    DAT_ffffab0e = 0;
    DAT_ffffab0c = 0;
    DAT_ffffab0d = 0;
  }
  if ((DAT_ffffad82 == '\0') && (DAT_ffffa428 == '\x01')) {
    fVar1 = (float)FUN_00002068(DAT_ffffad8c,&PTR_LAB_00069e70);
    fVar2 = (float)FUN_00002068(DAT_ffffaaf4,&DAT_00069e7c);
    DAT_ffffaae4 = fVar3 + (fVar2 + -1.0) * fVar1;
    DAT_ffffaae8 = rx8_first_order_filter(DAT_ffffaae4,DAT_ffffaae8,0.9375,1e-05);
    DAT_ffffaaec = DAT_ffffaae4;
    DAT_ffffab00 = DAT_ffffaae4;
  }
  return;
}


