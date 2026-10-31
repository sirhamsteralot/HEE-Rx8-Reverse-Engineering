/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005e4b2; body bytes: 110; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ccbe (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005e4b2(void)

{
  byte bVar1;
  byte snapshot_DAT_ffffd388;
  byte snapshot_DAT_ffffd389;
  char cVar5;
  undefined4 uVar4;
  
  cVar5 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff9170,0xff);
  uVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff9172,0xff);
  snapshot_DAT_ffffd389 = DAT_ffffd389;
  snapshot_DAT_ffffd388 = DAT_ffffd388;
  if (DAT_ffffd392 == '\0') {
    bVar1 = DAT_ffffd391 ^ DAT_ffffd389;
    ref_updateMemoryAtAddress_8bit_ADDR_VAL
              (&DAT_ffff9170,~(int)(char)(DAT_ffffd390 ^ DAT_ffffd388) & (int)cVar5);
    uVar4 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff9172,(int)(char)(~bVar1 & (byte)uVar4))
    ;
  }
  else {
    DAT_ffffd392 = DAT_ffffd392 + -1;
  }
  DAT_ffffd390 = snapshot_DAT_ffffd388;
  DAT_ffffd391 = snapshot_DAT_ffffd389;
  return uVar4;
}


