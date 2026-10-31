/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00061eb0; body bytes: 258; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000607a0 (258 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00061eb0(uint param_1,char param_2,undefined2 param_3)

{
  byte snapshot_DAT_ffffd6c3;
  byte bVar2;
  char cVar3;
  
  bVar2 = FUN_00062df8(param_1);
  snapshot_DAT_ffffd6c3 = DAT_ffffd6c3;
  cVar3 = FUN_00063046(param_1);
  if ((bVar2 == 0) || (bVar2 == 0x50)) {
    if ((snapshot_DAT_ffffd6c3 == 0) || (0x3f < snapshot_DAT_ffffd6c3)) {
      if ((snapshot_DAT_ffffd6c3 & 0x80) == 0x80) {
        DAT_ffffd6be = param_3;
        DAT_ffffd6c2 = 2;
        return;
      }
      if (param_2 == '\x01') goto LAB_00061f7a;
      if (param_2 != '\x02') {
        if (((param_1 & 0xffff) != 0) && ((param_1 & 0xffff) != 1)) {
          DAT_ffffd6be = param_3;
          DAT_ffffd6c2 = 8;
          return;
        }
        DAT_ffffd6be = param_3;
        DAT_ffffd6c2 = 9;
        return;
      }
      if (cVar3 != '\0') {
        DAT_ffffd6be = param_3;
        DAT_ffffd6c2 = 4;
        return;
      }
    }
    DAT_ffffd6c2 = 1;
  }
  else {
    if ((bVar2 == 0) || (0x3f < bVar2)) {
      if ((bVar2 & 0x80) != 0x80) {
        DAT_ffffd6be = param_3;
        DAT_ffffd6c2 = 8;
        return;
      }
      DAT_ffffd6be = param_3;
      DAT_ffffd6c2 = 5;
      return;
    }
    if ((snapshot_DAT_ffffd6c3 & 0x80) == 0x80) {
      DAT_ffffd6be = param_3;
      DAT_ffffd6c2 = 3;
      return;
    }
    if ((snapshot_DAT_ffffd6c3 != 0) && (snapshot_DAT_ffffd6c3 != 0x50)) {
      if (snapshot_DAT_ffffd6c3 == 0) {
        DAT_ffffd6be = param_3;
        DAT_ffffd6c2 = 8;
        return;
      }
      if (0x3f < snapshot_DAT_ffffd6c3) {
        DAT_ffffd6be = param_3;
        DAT_ffffd6c2 = 8;
        return;
      }
      DAT_ffffd6be = param_3;
      DAT_ffffd6c2 = 4;
      return;
    }
LAB_00061f7a:
    DAT_ffffd6c2 = 7;
  }
  DAT_ffffd6be = param_3;
  return;
}


