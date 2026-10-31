/* ROM address: 0x0001afb0; body bytes: 142; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001ba60 (142 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0001afb0(void)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8760,1);
  if (cVar1 == '\x01') {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff809c,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff80a2,0);
    uVar2 = 0;
    DAT_ffffad63 = 0;
    ref_updateMemoryAtAddress_float_VAL_ADDR(0,&DAT_ffff80ac);
    ref_updateMemoryAtAddress_float_VAL_ADDR(uVar2,&DAT_ffff80b4);
  }
  DAT_ffffadcd = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff809c,0);
  DAT_ffffadce = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff809e,0);
  DAT_ffffad58 = ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&DAT_ffff807c);
  DAT_ffffad78 = ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&DAT_ffff8084);
  DAT_ffffad60 = 0;
  DAT_ffffad5c = DAT_ffff9f08;
  DAT_ffffad5e = DAT_ffff9f0a;
  return;
}


