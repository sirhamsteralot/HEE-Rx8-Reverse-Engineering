/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004e4e8; body bytes: 116; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004bfbc (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 * FUN_0004e4e8(void)

{
  byte snapshot_DAT_ffffd26b;
  undefined2 *puVar2;
  
  snapshot_DAT_ffffd26b = DAT_ffffd26b;
  DAT_ffffcf84 = 0;
  puVar2 = &DAT_ffffcfaa;
  if ((((DAT_ffffcfaa < 0x19) || (DAT_ffffcf85 == '\0')) || (DAT_ffffcff8 != '\0')) ||
     (DAT_ffffcfe0 <= DAT_ffffcfe4)) {
    if ((DAT_ffffcf89 == '\0') &&
       (puVar2 = (undefined2 *)(uint)DAT_ffffd26b, puVar2 == (undefined2 *)0x1)) {
      puVar2 = (undefined2 *)rx8_add_u8_saturate(0x5e,0x27);
      DAT_ffffcf85 = (char)puVar2;
    }
  }
  else {
    puVar2 = (undefined2 *)&DAT_ffffcf85;
    DAT_ffffcf85 = '\0';
  }
  DAT_ffffcf89 = snapshot_DAT_ffffd26b;
  return puVar2;
}


