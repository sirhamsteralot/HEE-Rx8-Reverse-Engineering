/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003f510; body bytes: 164; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003faac (164 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0003f510(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  float snapshot_DAT_ffffad20;
  float snapshot_inferred_trim_b074_ffffb074_ffffb074;
  
  uVar4 = 0;
  snapshot_DAT_ffffad20 = DAT_ffffad20;
  snapshot_inferred_trim_b074_ffffb074_ffffb074 = inferred_trim_b074_ffffb074_ffffb074;
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff8720);
  fVar2 = fVar2 - 0.0003;
  fVar3 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(uVar4,&DAT_ffff8718);
  uVar1 = (uint)DAT_ffffc6de;
  if (uVar1 == 1) {
    uVar1 = (uint)DAT_ffffc6d8;
    if (uVar1 < 0x1f) {
      return uVar1;
    }
    if ((snapshot_inferred_trim_b074_ffffb074_ffffb074 < fVar2) && (snapshot_DAT_ffffad20 < 0.7)) {
      if (((fVar3 + 0.0003 < snapshot_inferred_trim_b074_ffffb074_ffffb074) && (((fVar2 <= snapshot_inferred_trim_b074_ffffb074_ffffb074 || (snapshot_DAT_ffffad20 <= 0.2)) || (0.7 <= snapshot_DAT_ffffad20)))) &&
         ((fVar3 + 0.0003 < snapshot_inferred_trim_b074_ffffb074_ffffb074 && (0.2 < snapshot_DAT_ffffad20)))) {
        return uVar1;
      }
      DAT_ffffc6df = 1;
      return uVar1;
    }
  }
  DAT_ffffc6df = 0;
  return uVar1;
}


