/* ROM address: 0x0001b3f2; body bytes: 558; decompiled */

void FUN_0001b3f2(void)

{
  char cVar3;
  uint uVar1;
  uint uVar2;
  char cVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  
  cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873e,0);
  cVar4 = DAT_ffffaa68;
  uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff809c,0);
  uVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff809e,0);
  if ((((uVar1 & 0xff) == 0) || ((uVar2 & 0xff) == 0)) && (DAT_ffffccc7 == '\x01')) {
    DAT_ffffad8d = '\x01';
  }
  else {
    DAT_ffffad8d = '\0';
  }
  if ((DAT_ffffad8d == '\x01') && (cVar3 == '\0')) {
    DAT_ffffad8e = 9 < DAT_ffffadc8;
    DAT_ffffadc8 = rx8_add_u16_saturate((int)(short)DAT_ffffadc8,1);
  }
  else {
    DAT_ffffad8e = '\0';
    DAT_ffffadc8 = 0;
  }
  if ((DAT_ffffadcc == '\0') && (DAT_ffffad8d == '\x01')) {
    DAT_ffffad68 = DAT_ffffb4b0;
    DAT_ffffad6c = DAT_ffffb4b4;
  }
  else if (cVar3 == '\0') {
    fVar5 = 1e-05;
    DAT_ffffad68 = rx8_first_order_filter(DAT_ffffb4b0,DAT_ffffad68,0.5,1e-05);
    DAT_ffffad6c = rx8_first_order_filter(DAT_ffffb4b4,DAT_ffffad6c,0.5,fVar5);
  }
  if ((DAT_ffffccba == '\x01') && (DAT_ffffadd0 == '\0')) {
    uVar2 = 0;
  }
  DAT_ffffadd0 = DAT_ffffccba;
  if (((DAT_ffffcc98 == '\x01') || (DAT_ffffcc99 == '\x01')) ||
     (cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873c,0), cVar3 == '\x01')) {
    uVar1 = 0;
    uVar2 = 0;
    DAT_ffffad58 = 15.0;
    DAT_ffffad78 = 15.0;
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff80a0,0);
  }
  else if (DAT_ffffad8e == '\x01') {
    if (cVar4 == '\x01') {
      uVar1 = 1;
    }
    else {
      uVar2 = 1;
    }
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff80a0,1);
    DAT_ffffad58 = rx8_clamp_float(DAT_ffffad68,10.0,20.0);
    DAT_ffffad78 = rx8_clamp_float(DAT_ffffad6c,10.0,20.0);
  }
  cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80a0,0);
  if (cVar4 == '\0') {
    ref_updateMemoryAtAddress_float_VAL_ADDR(0x41700000,&DAT_ffff807c);
    ref_updateMemoryAtAddress_float_VAL_ADDR(0x41700000,&DAT_ffff8084);
  }
  else if ((((uVar1 & 0xff) == 1) || ((uVar2 & 0xff) == 1)) && (DAT_ffffcc5e == '\x01')) {
    uVar7 = 0;
    fVar5 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff80ac);
    fVar5 = DAT_ffffad58 + fVar5;
    fVar6 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(uVar7,&DAT_ffff80b4);
    fVar6 = DAT_ffffad78 + fVar6;
    ref_updateMemoryAtAddress_float_VAL_ADDR(fVar5,&DAT_ffff807c);
    ref_updateMemoryAtAddress_float_VAL_ADDR(fVar6,&DAT_ffff8084);
  }
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff809c,uVar1);
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff809e,uVar2);
  DAT_ffffadcc = DAT_ffffad8d;
  return;
}


