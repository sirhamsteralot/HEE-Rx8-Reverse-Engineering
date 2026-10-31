/* ROM address: 0x00045e96; body bytes: 208; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00044cce (208 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00045e96(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_getFaultStatus__(0x68);
  if (((cVar2 == '\0') && (DAT_ffffccc2 == '\x01')) &&
     (cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8736,0), cVar2 == '\0')) {
    if (DAT_ffffa111 == '\x02') {
      DAT_ffffcc06 = rx8_add_u16_saturate((int)(short)DAT_ffffcc06,1);
      DAT_ffffcc08 = 0;
      if (0x18 < DAT_ffffcc06) {
        ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8736,1);
      }
    }
    else {
      DAT_ffffcc08 = rx8_add_u16_saturate((int)(short)DAT_ffffcc08,1);
      if (0x18 < DAT_ffffcc08) {
        DAT_ffffcc01 = 1;
        DAT_ffffcc06 = 0;
      }
    }
  }
  else {
    DAT_ffffcc08 = 0;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8736,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_0005fd38(0x68,1);
    return uVar1;
  }
  if (DAT_ffffcc01 == 1) {
    uVar1 = FUN_0005fd38(0x68,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc01;
}


