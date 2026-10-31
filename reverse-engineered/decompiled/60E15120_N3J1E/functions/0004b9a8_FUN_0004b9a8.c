/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004b9a8; body bytes: 118; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004ab60 (118 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004b9a8(void)

{
  byte snapshot_DAT_ffffce49;
  uint uVar2;
  undefined4 uVar3;
  
  snapshot_DAT_ffffce49 = DAT_ffffce49;
  uVar2 = (uint)DAT_ffffce4e;
  if ((uVar2 == 1) && (uVar2 = (uint)DAT_ffffce49, uVar2 == 0)) {
    if (DAT_ffffce3c < 0xdbbb) {
      if (DAT_ffffce3c < 0xdbbb) {
        if (DAT_ffffce3c < 0xdbbb) {
          if (DAT_ffffce3c == 0) {
            uVar3 = 4;
          }
          else {
            uVar3 = 3;
          }
          uVar2 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8770,uVar3);
          DAT_ffffce4e = snapshot_DAT_ffffce49;
          return uVar2;
        }
        uVar3 = 2;
      }
      else {
        uVar3 = 1;
      }
    }
    else {
      uVar3 = 0;
    }
    uVar2 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8770,uVar3);
  }
  DAT_ffffce4e = snapshot_DAT_ffffce49;
  return uVar2;
}


