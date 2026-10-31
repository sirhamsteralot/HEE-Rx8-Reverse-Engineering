/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00022db4; body bytes: 274; decompiled */

uint FUN_00022db4(void)

{
  byte snapshot_DAT_ffffccbc;
  uint uVar2;
  float fVar3;
  float fVar4;
  float arg0;
  
  fVar3 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&DAT_ffff807c);
  snapshot_DAT_ffffccbc = DAT_ffffccbc;
  arg0 = (fVar3 + 0.5) - 0.0;
  if (DAT_ffffb4b0 < fVar3 + 0.5) {
    if (DAT_ffffb4b0 < arg0) {
      DAT_ffffb400 = '\0';
    }
  }
  else {
    DAT_ffffb400 = '\x01';
  }
  uVar2 = (uint)DAT_ffffccbc;
  if (uVar2 == 1) {
    if (DAT_ffffb401 == '\0') {
      fVar4 = fVar3 + 0.5;
      if (DAT_ffffb4b0 < fVar3 + 0.5) {
        fVar4 = rx8_min_float(arg0,DAT_ffffb410 + fVar3);
      }
    }
    else {
      fVar4 = DAT_ffffb3f8;
      if (DAT_ffffb400 == '\x01') {
        if (1 < DAT_ffffb3fc) {
          fVar4 = rx8_max_float(5.0,DAT_ffffb3f8 - 0.05);
          DAT_ffffb3fc = 0;
        }
      }
      else if (1 < DAT_ffffb3fe) {
        fVar4 = rx8_max_float(5.0,DAT_ffffb3f8 - 0.05);
        DAT_ffffb3fe = 0;
      }
    }
  }
  else {
    DAT_ffffb3f8 = 0.0;
    fVar4 = DAT_ffffb3f8;
  }
  DAT_ffffb3f8 = fVar4;
  if (uVar2 == 1) {
    if (DAT_ffffb400 != '\x01') {
      DAT_ffffb3fc = 0;
      uVar2 = rx8_add_u16_saturate((int)(short)DAT_ffffb3fe,1);
      DAT_ffffb3fe = (short)uVar2;
      DAT_ffffb401 = snapshot_DAT_ffffccbc;
      return uVar2;
    }
    uVar2 = rx8_add_u16_saturate((int)(short)DAT_ffffb3fc,1);
    DAT_ffffb3fc = (ushort)uVar2;
  }
  else {
    DAT_ffffb3fc = 0;
  }
  DAT_ffffb3fe = 0;
  DAT_ffffb401 = snapshot_DAT_ffffccbc;
  return uVar2;
}


