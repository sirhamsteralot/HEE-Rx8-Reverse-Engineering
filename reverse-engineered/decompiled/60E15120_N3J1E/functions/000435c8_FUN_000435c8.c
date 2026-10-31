/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b828: Table 2D - 272 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x000435c8; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00042dfc (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000435c8(void)

{
  uint uVar1;
  undefined4 uVar2;
  float extraout_fr0;
  
  uVar1 = (uint)DAT_ffffca44;
  if (uVar1 == 1) {
    uVar2 = rx8_decode_u8_affine(0x3f800000,0,(int)DAT_ffffca3f);
    uVar1 = lookup_2d_descriptor_scaled(uVar2,&tbl_table_2d_272_0006b828);
    DAT_ffffc9a8 = DAT_ffffc9ac * extraout_fr0;
  }
  return uVar1;
}


