/* ROM address: 0x00049730; body bytes: 116; decompiled */

uint FUN_00049730(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcd14 = 0;
    DAT_ffffcd15 = '\0';
    uVar1 = 1;
  }
  else {
    if ((DAT_ffffcd21 == '\x01') && (DAT_ffffcd44 == '\x01')) {
      DAT_ffffcd14 = 1;
    }
    if ((DAT_ffffcd22 == '\x01') || (DAT_ffffcd45 == '\x01')) {
      DAT_ffffcd15 = '\x01';
    }
    if (DAT_ffffcd15 == '\x01') {
      uVar1 = dtc_set_fault_x0(0x1e,1);
      return uVar1;
    }
    uVar1 = (uint)DAT_ffffcd14;
    if (uVar1 == 1) {
      uVar1 = dtc_set_fault_x0(0x1e,2);
      return uVar1;
    }
  }
  return uVar1;
}


