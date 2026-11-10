/* ROM address: 0x00046d9a; body bytes: 56; decompiled */

uint FUN_00046d9a(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8748,0);
  if (cVar2 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x44,1);
    return uVar1;
  }
  if (DAT_ffffcc64 == 1) {
    uVar1 = dtc_set_fault_x0(0x44,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc64;
}


