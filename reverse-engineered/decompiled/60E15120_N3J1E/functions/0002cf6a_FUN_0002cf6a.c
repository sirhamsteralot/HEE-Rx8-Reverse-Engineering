/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002cf6a; body bytes: 230; decompiled */

uint FUN_0002cf6a(void)

{
  byte snapshot_DAT_ffffad18;
  byte snapshot_DAT_ffffbbcf;
  uint uVar3;
  uint uVar4;
  
  snapshot_DAT_ffffbbcf = DAT_ffffbbcf;
  snapshot_DAT_ffffad18 = inferred_ram_ad18_ffffad18_ffffad18;
  uVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8668,0);
  uVar3 = uVar3 & 0xff;
  if (uVar3 == 1) {
    uVar4 = (uint)snapshot_DAT_ffffad18;
    uVar3 = uVar4;
    if ((uVar4 != 1) || (uVar3 = (uint)snapshot_DAT_ffffbbcf, uVar3 != 1)) {
      if ((uVar4 == 0) && (snapshot_DAT_ffffbbcf == 0)) {
        DAT_ffffbcd9 = 0;
        DAT_ffffbcdc = 0;
        DAT_ffffbcde = 0;
        DAT_ffffbce4 = 0;
        return uVar3;
      }
      if (DAT_ffffbce4 != 1) {
        return (uint)DAT_ffffbce4;
      }
      if ((DAT_ffffbcdc != 0x177) && (DAT_ffffbcde != 0x177)) {
        if ((uVar4 == 1) && (snapshot_DAT_ffffbbcf == 0)) {
          uVar3 = rx8_add_u16_saturate((int)DAT_ffffbcdc,1);
          DAT_ffffbcdc = (short)uVar3;
          DAT_ffffbcde = 0;
          return uVar3;
        }
        if (uVar4 != 0) {
          return uVar4;
        }
        if (snapshot_DAT_ffffbbcf == 1) {
          DAT_ffffbcdc = 0;
          uVar3 = rx8_add_u16_saturate((int)DAT_ffffbcde,1);
          DAT_ffffbcde = (short)uVar3;
          return uVar3;
        }
        return (uint)snapshot_DAT_ffffbbcf;
      }
      uVar3 = rx8_add_u8_saturate((int)DAT_ffffbcd9,1);
      DAT_ffffbcd9 = (char)uVar3;
      DAT_ffffbce4 = 0;
      return uVar3;
    }
    DAT_ffffbce4 = 1;
    uVar3 = 1;
  }
  else {
    DAT_ffffbcd9 = '\0';
    DAT_ffffbce4 = 0;
  }
  DAT_ffffbcde = 0;
  DAT_ffffbcdc = 0;
  return uVar3;
}


