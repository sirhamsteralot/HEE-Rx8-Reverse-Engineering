/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00051a08; body bytes: 228; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004f764 (228 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00051a08(void)

{
  byte snapshot_DAT_ffffd0f4;
  byte snapshot_DAT_ffffd0f5;
  byte bVar5;
  char cVar6;
  char cVar7;
  uint uVar3;
  undefined4 uVar4;
  
  bVar5 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86dc,4);
  cVar6 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c2,0);
  cVar7 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c0,0);
  snapshot_DAT_ffffd0f5 = DAT_ffffd0f5;
  snapshot_DAT_ffffd0f4 = DAT_ffffd0f4;
  if (((((bVar5 < DAT_ffffd102) || ((DAT_ffffd108 == '\0' && (cVar6 == '\x01')))) ||
       ((DAT_ffffd107 == '\0' && (cVar7 == '\x01')))) &&
      ((DAT_ffffcf78 == '\0' && (DAT_ffffcf85 == '\0')))) ||
     (uVar3 = (uint)DAT_ffffd1c5, uVar3 == 1)) {
    uVar3 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86c6,0);
  }
  else if (((DAT_ffffd104 == '\0') && (uVar3 = (uint)DAT_ffffd0f4, uVar3 == 1)) ||
          ((DAT_ffffd105 == '\0' && (uVar3 = (uint)DAT_ffffd0f5, uVar3 == 1)))) {
    uVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff869c,0);
    uVar3 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86c6,uVar4);
  }
  DAT_ffffd102 = bVar5;
  DAT_ffffd107 = cVar7;
  DAT_ffffd108 = cVar6;
  DAT_ffffd104 = snapshot_DAT_ffffd0f4;
  DAT_ffffd105 = snapshot_DAT_ffffd0f5;
  return uVar3;
}


