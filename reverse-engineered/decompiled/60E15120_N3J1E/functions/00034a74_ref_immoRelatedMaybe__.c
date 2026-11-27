/* [ADDITIONAL SOURCE REVIEW]
 * immo_key_defaults_init [medium]: ref_immoRelatedMaybe__ (unique_exact_bytes to 60E0FC00 0x35194). If c26c==c270==-1 (erased EEPROM) -> defaults 0x10001 / 0x55aa55aa; if c27a/c27c invalid -> 0x55aa / 0xb7e3; sets c20c=500, c210=0xfa, c222=1, c21e=5.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00034a74; body bytes: 110; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00035194 (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

int candidate_immo_key_defaults_init(void)

{
  int snapshot_DAT_ffffc270;
  int iVar2;
  
  snapshot_DAT_ffffc270 = immo_key_reg_b_ffffc270;
  immo_timer_a_ffffc20c = 500;
  DAT_ffffc210 = 0xfa;
  DAT_ffffc222 = 1;
  immo_command_substate_ffffc21e = 5;
  iVar2 = immo_key_reg_a_ffffc26c;
  if ((immo_key_reg_a_ffffc26c == -1) && (iVar2 = snapshot_DAT_ffffc270, immo_key_reg_b_ffffc270 == -1)) {
    immo_key_reg_a_ffffc26c = 0x10001;
    immo_key_reg_b_ffffc270 = 0x55aa55aa;
  }
  if (((DAT_ffffc27a == -1) && (DAT_ffffc27c == -1)) || ((DAT_ffffc27a == 0 && (DAT_ffffc27c == 0)))
     ) {
    iVar2 = 0x55aa;
    DAT_ffffc27a = 0x55aa;
    DAT_ffffc27c = -0x481d;
  }
  return iVar2;
}


