/* ROM address: 0x0004621c; body bytes: 244; decompiled */

uint FUN_0004621c(void)

{
  char cVar2;
  uint uVar1;
  undefined4 uVar3;
  
  if ((((DAT_ffffb43e == '\x01') || (DAT_ffffb43d == '\x01')) || (DAT_ffffa228 == '\x02')) ||
     (DAT_ffffa229 == '\x01')) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff873e,uVar3);
  if (DAT_ffffcc15 == '\x01') {
    cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873e,0);
    if (cVar2 != '\x01') {
      if (0xf9 < DAT_ffffcc18) {
        DAT_ffffcc14 = 1;
      }
      DAT_ffffcc18 = rx8_add_u16_saturate((int)(short)DAT_ffffcc18,1);
      DAT_ffffcc16 = 0;
      goto LAB_000462ec;
    }
    if (0x18 < DAT_ffffcc16) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff873c,1);
    }
    DAT_ffffcc16 = rx8_add_u16_saturate((int)(short)DAT_ffffcc16,1);
  }
  else {
    DAT_ffffcc16 = 0;
  }
  DAT_ffffcc18 = 0;
LAB_000462ec:
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873c,0);
  if (cVar2 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x62,1);
    return uVar1;
  }
  if (DAT_ffffcc14 == 1) {
    uVar1 = dtc_set_fault_x0(0x62,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc14;
}


