/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003432a; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00034a4a (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0003432a(void)

{
  byte snapshot_DAT_ffffb0ca;
  uint uVar2;
  
  snapshot_DAT_ffffb0ca = DAT_ffffb0ca;
  uVar2 = (uint)DAT_ffffb0ca;
  if (uVar2 == 1) {
    if (DAT_ffffc198 == '\0') {
      DAT_ffffc168 = 0;
    }
    else {
      uVar2 = rx8_add_u16_saturate((int)DAT_ffffc168,1);
      DAT_ffffc168 = (short)uVar2;
    }
  }
  DAT_ffffc198 = snapshot_DAT_ffffb0ca;
  return uVar2;
}


