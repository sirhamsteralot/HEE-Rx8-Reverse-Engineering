/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000455bc; body bytes: 612; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000455f6) */
/* WARNING: Removing unreachable block (ram,0x000455e0) */

uint FUN_000455bc(void)

{
  bool bVar1;
  ushort snapshot_DAT_ffffcbe6;
  char cVar4;
  uint uVar3;
  ushort uVar5;
  
  snapshot_DAT_ffffcbe6 = DAT_ffffcbe6;
  DAT_ffffcbd6 = DAT_ffffcbe6;
  DAT_ffffcbe6 = DAT_ffffcbe4;
  DAT_ffffcbe4 = inferred_throttle_sensor_volts_ffffad5c_ffffad5c;
  if (DAT_ffffb4cc <= snapshot_DAT_ffffcbe6) {
    uVar5 = snapshot_DAT_ffffcbe6 - DAT_ffffb4cc;
  }
  else {
    uVar5 = DAT_ffffb4cc - snapshot_DAT_ffffcbe6;
  }
  bVar1 = DAT_ffffb4cc > snapshot_DAT_ffffcbe6;
  if (((bool)DAT_ffffcbea == bVar1) && (DAT_ffffcbe2 != '\0')) {
    if (uVar5 < 0x5f0) {
      DAT_ffffcbd8 = 0;
    }
    if (uVar5 < 0x937) {
      DAT_ffffcbda = 0;
    }
    if (uVar5 < 0xc4a) {
      DAT_ffffcbdc = 0;
    }
    if (uVar5 < 0x1168) {
      DAT_ffffcbde = 0;
    }
    if (uVar5 < 0x154d) {
      DAT_ffffcbe0 = 0;
    }
    if (0x5ef < uVar5) {
      DAT_ffffcbd8 = rx8_add_u16_saturate((int)(short)DAT_ffffcbd8,1);
    }
    if (0x936 < uVar5) {
      DAT_ffffcbda = rx8_add_u16_saturate((int)(short)DAT_ffffcbda,1);
    }
    if (0xc49 < uVar5) {
      DAT_ffffcbdc = rx8_add_u16_saturate((int)(short)DAT_ffffcbdc,1);
    }
    if (0x1167 < uVar5) {
      DAT_ffffcbde = rx8_add_u16_saturate((int)(short)DAT_ffffcbde,1);
    }
    if (0x154c < uVar5) {
      DAT_ffffcbe0 = rx8_add_u16_saturate((int)(short)DAT_ffffcbe0,1);
    }
  }
  else {
    DAT_ffffcbd8 = 0;
    DAT_ffffcbda = 0;
    DAT_ffffcbdc = 0;
    DAT_ffffcbde = 0;
    DAT_ffffcbe0 = 0;
  }
  DAT_ffffcbea = bVar1;
  if ((DAT_ffffcbe2 == '\x01') &&
     ((((0x5d < DAT_ffffcbd8 || (0x44 < DAT_ffffcbda)) || (0x31 < DAT_ffffcbdc)) ||
      ((0x25 < DAT_ffffcbde || (0x1e < DAT_ffffcbe0)))))) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8728,1);
    DAT_ffffcbe8 = 0;
  }
  else if ((DAT_ffffcbe2 == '\x01') &&
          (((DAT_ffffcbd8 == 0 && (DAT_ffffcbda == 0)) &&
           ((DAT_ffffcbdc == 0 && ((DAT_ffffcbde == 0 && (DAT_ffffcbe0 == 0)))))))) {
    if (0xf9 < DAT_ffffcbe8) {
      DAT_ffffcbd4 = 1;
    }
    DAT_ffffcbe8 = rx8_add_u16_saturate((int)(short)DAT_ffffcbe8,1);
  }
  else {
    DAT_ffffcbe8 = 0;
  }
  cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8728,0);
  if (cVar4 != '\x01') {
    if (DAT_ffffcbd4 != 1) {
      return (uint)DAT_ffffcbd4;
    }
    uVar3 = dtc_set_fault_x0(0x4e,2);
    return uVar3;
  }
  uVar3 = dtc_set_fault_x0(0x4e,1);
  return uVar3;
}


