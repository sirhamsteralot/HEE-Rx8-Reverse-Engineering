/* ROM address: 0x00046fee; body bytes: 150; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004607a (150 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00046fee(void)

{
  char cVar2;
  uint uVar1;
  
  if (DAT_ffffcc6c == '\0') {
    FUN_0000b5fa();
  }
  if (DAT_ffffcc6c == '\x01') {
    if (DAT_ffffa229 == '\x01') {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8758,1);
      DAT_ffffcc6e = 0;
    }
    else {
      if (0xf9 < DAT_ffffcc6e) {
        DAT_ffffcc6d = 1;
      }
      DAT_ffffcc6e = rx8_add_u16_saturate((int)(short)DAT_ffffcc6e,1);
    }
  }
  else {
    DAT_ffffcc6e = 0;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8758,0);
  if (cVar2 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x5e,1);
    return uVar1;
  }
  if (DAT_ffffcc6d == 1) {
    uVar1 = dtc_set_fault_x0(0x5e,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc6d;
}


