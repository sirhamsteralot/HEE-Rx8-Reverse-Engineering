/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00043b2c; body bytes: 122; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00043360 (122 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00043b2c(void)

{
  byte snapshot_DAT_ffffb07c;
  uint uVar2;
  
  snapshot_DAT_ffffb07c = DAT_ffffb07c;
  if (DAT_ffffb0ca == '\x01') {
    DAT_ffffcb3b = '\x01';
    DAT_ffffcb3a = 0;
  }
  if ((DAT_ffffcb3b == '\x01') &&
     (((DAT_ffffcb5e == '\0' && (DAT_ffffb07c == 1)) ||
      ((DAT_ffffb07c == 1 && (0x138 < DAT_ffffcb54)))))) {
    DAT_ffffcb3a = 1;
    DAT_ffffcb3b = '\0';
  }
  uVar2 = (uint)DAT_ffffb07c;
  if (uVar2 == 1) {
    uVar2 = rx8_add_u16_saturate((int)(short)DAT_ffffcb54,1);
    DAT_ffffcb54 = (ushort)uVar2;
  }
  else {
    DAT_ffffcb54 = 0;
  }
  DAT_ffffcb5e = snapshot_DAT_ffffb07c;
  return uVar2;
}


