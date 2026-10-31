/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004f730; body bytes: 110; decompiled */

char FUN_0004f730(void)

{
  ushort snapshot_DAT_ffffcfa8;
  ushort snapshot_DAT_ffffcfaa;
  
  snapshot_DAT_ffffcfaa = DAT_ffffcfaa;
  snapshot_DAT_ffffcfa8 = DAT_ffffcfa8;
  if (((DAT_ffffcfbf == '\x01') && (DAT_ffffcffb == '\0')) && (DAT_ffffcfa8 <= DAT_ffffcfaa)) {
    DAT_ffffcff4 = rx8_clamp_float(DAT_ffffcfec - DAT_ffffcff0,0.0,0.038);
  }
  if ((DAT_ffffcfbe == '\x01') && (snapshot_DAT_ffffcfa8 <= snapshot_DAT_ffffcfaa)) {
    DAT_ffffcffb = 1;
  }
  else {
    DAT_ffffcffb = 0;
  }
  return DAT_ffffcfbe;
}


