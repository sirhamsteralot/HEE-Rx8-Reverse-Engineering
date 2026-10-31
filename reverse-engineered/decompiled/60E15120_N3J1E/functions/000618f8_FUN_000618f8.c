/* [RX8DEFS 2026-09-30 000618f8]
 * Suggested interpretation: inferred_apply_diagnostic_index_policy.
 * Confidence: indexed byte-policy use verified; individual DTC mapping unresolved.
 * Reads bytes from 0x7e704 indexed by param_1 and branches on values zero/one. Related reads occur in 6071e, 61450, 615c6 and 61d28. This supports diagnostic policy bytes but does not independently map the upstream #1 bank at 7e678/7e679 to SAE DTC identities.
 */
/* ROM address: 0x000618f8; body bytes: 194; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000601e8 (194 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000618f8(uint param_1,byte param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 8;
  param_1 = param_1 & 0xffff;
  cVar1 = (&DAT_0007e32a)[param_1];
  if (cVar1 == '\0') {
    if ((param_2 == 0) || (0x3f < param_2)) {
      if ((param_2 & 0x80) == 0x80) {
        if ((&DAT_0007e704)[param_1] == '\0') {
          uVar2 = 5;
        }
        else if ((&DAT_0007e704)[param_1] == '\x01') {
          if ((&CAL_DTC_0300_Enable_Disable_1_1129)[param_1] == '\0') {
            uVar2 = 4;
          }
          else if ((&CAL_DTC_0300_Enable_Disable_1_1129)[param_1] == '\x01') {
            uVar2 = 3;
          }
        }
      }
    }
    else {
      uVar2 = 6;
    }
  }
  else if (((cVar1 == '\x03') || (cVar1 == '\x01')) || (cVar1 == '\x02')) {
    if ((param_2 == 0) || (0x3f < param_2)) {
      if ((param_2 & 0x80) == 0x80) {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 2;
    }
  }
  return uVar2;
}


