/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002d07e; body bytes: 230; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002d722 (230 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0002d07e(void)

{
  byte snapshot_DAT_ffffad18;
  byte snapshot_DAT_ffffbbcf;
  uint uVar3;
  uint uVar4;
  
  snapshot_DAT_ffffbbcf = DAT_ffffbbcf;
  snapshot_DAT_ffffad18 = inferred_ram_ad18_ffffad18_ffffad18;
  uVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8668,0);
  if ((uVar3 & 0xff) == 1) {
    uVar4 = (uint)snapshot_DAT_ffffad18;
    if ((uVar4 != 0) || (snapshot_DAT_ffffbbcf != 0)) {
      if ((uVar4 == 1) && (snapshot_DAT_ffffbbcf == 1)) {
        DAT_ffffbcda = 0;
        DAT_ffffbce0 = 0;
        DAT_ffffbce2 = 0;
        DAT_ffffbce5 = 0;
        return 1;
      }
      if (DAT_ffffbce5 != 1) {
        return (uint)DAT_ffffbce5;
      }
      if ((DAT_ffffbce0 != 0x177) && (DAT_ffffbce2 != 0x177)) {
        if ((uVar4 == 1) && (snapshot_DAT_ffffbbcf == 0)) {
          uVar3 = rx8_add_u16_saturate((int)DAT_ffffbce0,1);
          DAT_ffffbce0 = (short)uVar3;
          DAT_ffffbce2 = 0;
          return uVar3;
        }
        if (uVar4 != 0) {
          return uVar4;
        }
        if (snapshot_DAT_ffffbbcf == 1) {
          DAT_ffffbce0 = 0;
          uVar3 = rx8_add_u16_saturate((int)DAT_ffffbce2,1);
          DAT_ffffbce2 = (short)uVar3;
          return uVar3;
        }
        return (uint)snapshot_DAT_ffffbbcf;
      }
      uVar3 = rx8_add_u8_saturate((int)DAT_ffffbcda,1);
      DAT_ffffbcda = (char)uVar3;
      DAT_ffffbce5 = 0;
      return uVar3;
    }
    DAT_ffffbce5 = 1;
  }
  else {
    DAT_ffffbcda = '\0';
    DAT_ffffbce5 = 0;
  }
  DAT_ffffbce2 = 0;
  DAT_ffffbce0 = 0;
  return uVar3 & 0xff;
}


