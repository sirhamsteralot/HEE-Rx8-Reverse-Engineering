/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006bac8: Table 2D - 388 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bad4: Table 2D - 389 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004a770; body bytes: 138; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004972c (138 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0004a770(void)

{
  undefined4 uVar1;
  float snapshot_DAT_ffffcd78;
  
  if (DAT_ffffd1c5 == '\0') {
    snapshot_DAT_ffffcd78 = DAT_ffffcd78;
    uVar1 = rx8_decode_u16_affine(0x42000000,0,(int)DAT_ffffcd88);
    DAT_ffffcda0 = (float)lookup_2d_descriptor_scaled(uVar1,&PTR_PTR_0006bac8);
    DAT_ffffcda4 = (float)lookup_2d_descriptor_scaled(uVar1,&PTR_PTR_0006bad4);
    if (snapshot_DAT_ffffcd78 < DAT_ffffcda0) {
      DAT_ffffcd80 = '\x01';
    }
    if (DAT_ffffcda4 <= snapshot_DAT_ffffcd78) {
      DAT_ffffcd81 = '\x01';
    }
    if ((DAT_ffffcd80 == '\x01') && (DAT_ffffcd81 == '\x01')) {
      DAT_ffffcd82 = 1;
    }
  }
  else {
    DAT_ffffcd80 = '\0';
    DAT_ffffcd81 = '\0';
    DAT_ffffcd82 = 0;
  }
  return;
}


