/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069c94: Table 2D - 318 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001e99c; body bytes: 186; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001f3fc (186 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0001e99c(void)

{
  short sVar1;
  char cVar2;
  uint uVar3;
  float snapshot_DAT_ffffadf4;
  
  cVar2 = DAT_ffffb0de;
  sVar1 = DAT_ffffb0d4;
  snapshot_DAT_ffffadf4 = DAT_ffffadf4;
  if (((DAT_ffffb0ff == '\0') && (DAT_ffffb0de == '\x01')) ||
     ((DAT_ffffb0f8 != 0 && (DAT_ffffb0d4 == 0)))) {
    DAT_ffffb0d6 = rx8_lookup_2d_raw_u16(DAT_ffffb220,&tbl_table_2d_318_check_datatype_00069c94);
  }
  if ((((closed_loop_active_ffffae1f == 1) && (1.0 < snapshot_DAT_ffffadf4)) && (snapshot_DAT_ffffadf4 < 1.002)) && (DAT_ffffb0d6 != 0)) {
    DAT_ffffb0d6 = DAT_ffffb0d6 + -1;
  }
  if (DAT_ffffb0d6 != 0) {
    if (DAT_ffffb0f6 < 0x1d5) {
      uVar3 = rx8_add_u16_saturate((int)(short)DAT_ffffb0f6,1);
      DAT_ffffb0f6 = (short)uVar3;
      DAT_ffffb0f8 = sVar1;
      DAT_ffffb0ff = cVar2;
      return uVar3;
    }
    DAT_ffffb0d6 = 0;
  }
  DAT_ffffb0f6 = 0;
  DAT_ffffb0f8 = sVar1;
  DAT_ffffb0ff = cVar2;
  return (uint)closed_loop_active_ffffae1f;
}


