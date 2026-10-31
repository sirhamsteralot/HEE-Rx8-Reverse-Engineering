/* [ADDITIONAL SOURCE REVIEW]
 * can216_unpack_mixed_width_fields [high]: Unique exact reference match and relocated literal operands map G-ROM names to 16-bit words at 0xffffbad4, bad6, bada; bytes at bad8 and badc. G-ROM byteN names are not accurate widths or a contiguous raw payload.
 * RAM 0xffffbad4 can216_unpacked_field_0 (uint16): Source raw bytes 0..1 at bab8/bab9.
 * RAM 0xffffbad6 can216_unpacked_field_1 (uint16): Source raw bytes 2..3.
 * RAM 0xffffbad8 can216_unpacked_field_2 (uint8): Source raw byte 4.
 * RAM 0xffffbada can216_unpacked_field_3 (uint16): Source raw bytes 5..6.
 * RAM 0xffffbadc can216_unpacked_field_4 (uint8): Source raw byte 7.
 */
/* ROM address: 0x00028eb8; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00029860 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

void can216_unpack_mixed_width_fields(void)

{
  can216_unpacked_field_0_ffffbad4 = (ushort)DAT_ffffbab8 * 0x100 + (ushort)DAT_ffffbab9;
  can216_unpacked_field_1_ffffbad6 = (ushort)DAT_ffffbaba * 0x100 + (ushort)DAT_ffffbabb;
  can216_unpacked_field_2_ffffbad8 = DAT_ffffbabc;
  can216_unpacked_field_3_ffffbada = (ushort)DAT_ffffbabd * 0x100 + (ushort)DAT_ffffbabe;
  can216_unpacked_field_4_ffffbadc = DAT_ffffbabf;
  return;
}


