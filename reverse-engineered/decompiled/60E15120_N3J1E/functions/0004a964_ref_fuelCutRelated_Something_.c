/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004a964; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00049920 (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_fuelCutRelated_Something_(void)

{
  byte snapshot_DAT_ffffa415;
  uint uVar2;
  uint uVar3;
  
  snapshot_DAT_ffffa415 = DAT_ffffa415;
  DAT_ffffcdd1 = 0;
  if (DAT_ffffcdd2 == '\x01') {
    DAT_ffffcdd1 = 1;
    DAT_ffffcdd2 = '\0';
    uVar2 = 1;
  }
  else {
    uVar3 = (uint)DAT_ffffa415;
    if (uVar3 == 0) {
      uVar2 = (uint)DAT_ffffcdd0;
      if (uVar2 == 0x17) {
        DAT_ffffcdd1 = 1;
      }
    }
    else {
      uVar2 = rx8_add_u8_saturate((int)(char)DAT_ffffcdd0,1);
      if ((uVar2 & 0xff) == uVar3) {
        DAT_ffffcdd1 = 1;
      }
    }
  }
  DAT_ffffcdd0 = snapshot_DAT_ffffa415;
  return uVar2;
}


