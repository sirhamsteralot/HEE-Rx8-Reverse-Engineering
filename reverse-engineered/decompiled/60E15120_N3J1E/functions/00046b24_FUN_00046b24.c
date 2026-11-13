/* ROM address: 0x00046b24; body bytes: 330; decompiled */

void FUN_00046b24(void)

{
  char cVar2;
  char cVar3;
  uint uVar1;
  uint uVar4;
  float arg1;
  float fVar5;
  
  arg1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&inferred_ram_807c_ffff807c_ffff807c);
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff809c,0);
  cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff809e,0);
  uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8744,0);
  fVar5 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x41a00000,&DAT_ffff8094);
  fVar5 = rx8_absolute_difference(fVar5,arg1);
  if ((DAT_ffffcc5c == '\x01') && ((cVar2 == '\x01' || (cVar3 == '\x01')))) {
    if (((arg1 < 9.625) || (20.375 < arg1)) || (fVar5 < 1.8)) {
      DAT_ffffcc62 = 0;
      if (DAT_ffffcc60 != 0) {
        uVar1 = 1;
      }
      DAT_ffffcc60 = rx8_add_u16_saturate((int)DAT_ffffcc60,1);
    }
    else {
      DAT_ffffcc60 = 0;
      if (DAT_ffffcc62 != 0) {
        DAT_ffffcc5d = '\x01';
      }
      DAT_ffffcc62 = rx8_add_u16_saturate((int)DAT_ffffcc62,1);
    }
  }
  else {
    DAT_ffffcc62 = 0;
    DAT_ffffcc60 = 0;
  }
  uVar4 = uVar1 & 0xff;
  if (engine_running_flag_ffffaa68 == '\x01') {
    if ((cVar2 != '\x01') && (cVar3 != '\x01')) goto LAB_00046c74;
    if (uVar4 != 1) {
      DAT_ffffcc5e = 1;
      goto LAB_00046c74;
    }
  }
  else if (cVar3 != '\0') {
    if (uVar4 == 0) {
      DAT_ffffcc5e = 1;
    }
    goto LAB_00046c74;
  }
  DAT_ffffcc5e = 0;
LAB_00046c74:
  if (uVar4 == 1) {
    dtc_set_fault_x0(99,1);
  }
  else if (DAT_ffffcc5d == '\x01') {
    dtc_set_fault_x0(99,2);
  }
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8744,uVar1);
  return;
}


