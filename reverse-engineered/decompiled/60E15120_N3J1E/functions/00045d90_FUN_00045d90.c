/* ROM address: 0x00045d90; body bytes: 208; decompiled */

uint FUN_00045d90(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_getFaultStatus__(0x69);
  if (((cVar2 == '\0') && (DAT_ffffccc2 == '\x01')) &&
     (cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8734,0), cVar2 == '\0')) {
    if (DAT_ffffa111 == '\x01') {
      DAT_ffffcc02 = rx8_add_u16_saturate((int)(short)DAT_ffffcc02,1);
      DAT_ffffcc04 = 0;
      if (0x18 < DAT_ffffcc02) {
        ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8734,1);
      }
    }
    else {
      DAT_ffffcc04 = rx8_add_u16_saturate((int)(short)DAT_ffffcc04,1);
      if (0x18 < DAT_ffffcc04) {
        DAT_ffffcc00 = 1;
        DAT_ffffcc02 = 0;
      }
    }
  }
  else {
    DAT_ffffcc04 = 0;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8734,0);
  if (cVar2 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x69,1);
    return uVar1;
  }
  if (DAT_ffffcc00 == 1) {
    uVar1 = dtc_set_fault_x0(0x69,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc00;
}


