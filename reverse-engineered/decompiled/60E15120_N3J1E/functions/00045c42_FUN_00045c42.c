/* ROM address: 0x00045c42; body bytes: 208; decompiled */

uint FUN_00045c42(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_getFaultStatus__(0x66);
  if (((cVar2 == '\0') && (DAT_ffffccc2 == '\x01')) &&
     (cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8732,0), cVar2 == '\0')) {
    if (DAT_ffffa110 == '\x02') {
      DAT_ffffcbfa = rx8_add_u16_saturate((int)(short)DAT_ffffcbfa,1);
      DAT_ffffcbfc = 0;
      if (0x18 < DAT_ffffcbfa) {
        ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8732,1);
      }
    }
    else {
      DAT_ffffcbfc = rx8_add_u16_saturate((int)(short)DAT_ffffcbfc,1);
      if (0x18 < DAT_ffffcbfc) {
        DAT_ffffcbf5 = 1;
        DAT_ffffcbfa = 0;
      }
    }
  }
  else {
    DAT_ffffcbfc = 0;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8732,0);
  if (cVar2 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x66,1);
    return uVar1;
  }
  if (DAT_ffffcbf5 == 1) {
    uVar1 = dtc_set_fault_x0(0x66,2);
    return uVar1;
  }
  return (uint)DAT_ffffcbf5;
}


