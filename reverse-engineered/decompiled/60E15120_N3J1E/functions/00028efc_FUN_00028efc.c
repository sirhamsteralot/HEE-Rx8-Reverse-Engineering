/* ROM address: 0x00028efc; body bytes: 228; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00028f20) */
/* WARNING: Removing unreachable block (ram,0x00028f2a) */
/* WARNING: Removing unreachable block (ram,0x00028f34) */
/* WARNING: Removing unreachable block (ram,0x00028f40) */
/* WARNING: Removing unreachable block (ram,0x00028f4a) */
/* WARNING: Removing unreachable block (ram,0x00028f54) */

byte FUN_00028efc(void)

{
  if (can216_unpacked_field_0_ffffbad4 != -1) {
    DAT_ffffbac4 = 0x44000000;
  }
  DAT_ffffbac8 = rx8_decode_u16_affine(0x3f800000,0xc4000000,(int)can216_unpacked_field_1_ffffbad6);
  DAT_ffffbacc = rx8_decode_u8_affine(0x42160000,0,(int)can216_unpacked_field_2_ffffbad8);
  DAT_ffffbad0 = (can216_unpacked_field_4_ffffbadc & 8) == 8;
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8660,(can216_unpacked_field_4_ffffbadc & 2) != 0);
  DAT_ffffbad1 = (can216_unpacked_field_4_ffffbadc & 2) == 2;
  return can216_unpacked_field_4_ffffbadc & 2;
}


