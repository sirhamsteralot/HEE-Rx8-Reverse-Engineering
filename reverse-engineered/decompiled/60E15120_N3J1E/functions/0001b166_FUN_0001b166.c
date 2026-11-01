/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001b166; body bytes: 526; decompiled */

uint FUN_0001b166(void)

{
  short sVar1;
  char cVar2;
  byte snapshot_DAT_ffffccbc;
  char cVar6;
  char cVar7;
  ushort uVar5;
  uint uVar4;
  float fVar8;
  float fVar9;
  float extraout_fr0;
  float fVar10;
  float fVar11;
  undefined4 uVar12;
  
  snapshot_DAT_ffffccbc = DAT_ffffccbc;
  cVar2 = DAT_ffffcc99;
  cVar7 = DAT_ffffcc98;
  sVar1 = DAT_ffffad88;
  fVar11 = inferred_ram_b410_ffffb410_ffffb410;
  if (DAT_ffffadd1 == '\0') {
    DAT_ffffad70 = DAT_ffffb4b0;
    DAT_ffffad74 = DAT_ffffb4b4;
    DAT_ffffad98 = DAT_ffffb4b0;
    DAT_ffffad9c = DAT_ffffb4b4;
    DAT_ffffadd1 = '\x01';
  }
  else if (((DAT_ffffcc98 == '\0') && (DAT_ffffcc99 == '\0')) &&
          (cVar6 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873c,0), cVar6 == '\0')) {
    fVar8 = 1e-05;
    DAT_ffffad70 = rx8_first_order_filter(DAT_ffffb4b0,DAT_ffffad70,0.5,1e-05);
    DAT_ffffad74 = rx8_first_order_filter(DAT_ffffb4b4,DAT_ffffad74,0.5,fVar8);
  }
  fVar8 = rx8_absolute_difference(DAT_ffffad70,DAT_ffffad98);
  fVar9 = rx8_absolute_difference(DAT_ffffad74,DAT_ffffad9c);
  if (((((-80.0 < DAT_ffffb4bc) || (cVar7 != '\0')) ||
       ((cVar2 != '\0' || ((DAT_ffffb4f9 != '\0' || (0.244 <= fVar8)))))) || (0.244 <= fVar9)) ||
     ((((DAT_ffffccc1 != '\x01' || (DAT_ffffb4ed != '\x01')) || (snapshot_DAT_ffffccbc != 0)) ||
      ((cVar7 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873e,0), cVar7 != '\0' || (5.0 <= fVar11))))
     )) {
    uVar5 = 0;
  }
  else {
    uVar5 = rx8_add_u16_saturate((int)sVar1,1);
  }
  uVar4 = (uint)snapshot_DAT_ffffccbc;
  uVar12 = 0;
  if (uVar4 == 1) {
    ref_updateMemoryAtAddress_float_VAL_ADDR(0,&DAT_ffff80ac);
    uVar4 = ref_updateMemoryAtAddress_float_VAL_ADDR(uVar12,&DAT_ffff80b4);
  }
  else if (0xf < uVar5) {
    fVar9 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&inferred_ram_807c_ffff807c_ffff807c);
    uVar4 = ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&DAT_ffff8084);
    fVar8 = extraout_fr0;
    if (fVar11 + fVar9 < DAT_ffffad70 + 0.061) {
      fVar10 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(uVar12,&DAT_ffff80ac);
      fVar9 = rx8_clamp_float(((fVar10 + DAT_ffffad70) - fVar9) + 0.061,0.0,0.875);
      uVar4 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar9,&DAT_ffff80ac);
      uVar5 = 0;
    }
    if (fVar11 + fVar8 < DAT_ffffad74 + 0.061) {
      fVar11 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(uVar12,&DAT_ffff80b4);
      fVar11 = rx8_clamp_float(((fVar11 + DAT_ffffad74) - fVar8) + 0.061,0.0,0.875);
      uVar4 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar11,&DAT_ffff80b4);
      uVar5 = 0;
    }
  }
  DAT_ffffad88 = uVar5;
  DAT_ffffad98 = DAT_ffffad70;
  DAT_ffffad9c = DAT_ffffad74;
  return uVar4;
}


