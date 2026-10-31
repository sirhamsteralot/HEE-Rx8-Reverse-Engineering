/* [ADDITIONAL SOURCE REVIEW]
 * maf_operating_range [high]: b0fe = MAF range index 0..3 from mass_air_flow a9ec bands (<1, <9, <22, else) with hysteresis flags b101/b102/b103.
 * RAM 0xffffb0fe maf_range_index (uint8): b0fe = 0..3 MAF operating range from mass_air_flow bands (<1, <9, <22).
 * RAM 0xffffb101 maf_band_low (uint8): b101 = maf < 1 (hysteresis 0.4).
 * RAM 0xffffb102 maf_band_mid (uint8): b102 = maf < 9 (hysteresis 8.4).
 * RAM 0xffffb103 maf_band_high (uint8): b103 = maf < 22 (hysteresis 21.4); all clear -> range 3.
 */
/* ROM address: 0x0001e842; body bytes: 148; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001f2a2 (148 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * maf_operating_range(void)

{
  if (mass_air_flow_ffffa9ec < 1.0) {
    if (mass_air_flow_ffffa9ec < 0.39999998) {
      maf_band_low_ffffb101 = '\0';
    }
  }
  else {
    maf_band_low_ffffb101 = '\x01';
  }
  if (mass_air_flow_ffffa9ec < 9.0) {
    if (mass_air_flow_ffffa9ec < 8.4) {
      maf_band_mid_ffffb102 = '\0';
    }
  }
  else {
    maf_band_mid_ffffb102 = '\x01';
  }
  if (mass_air_flow_ffffa9ec < 22.0) {
    if (mass_air_flow_ffffa9ec < 21.4) {
      maf_band_high_ffffb103 = '\0';
    }
  }
  else {
    maf_band_high_ffffb103 = '\x01';
  }
  if (maf_band_low_ffffb101 == '\0') {
    maf_range_index_ffffb0fe = 0;
  }
  else if (maf_band_mid_ffffb102 == '\0') {
    maf_range_index_ffffb0fe = 1;
  }
  else if (maf_band_high_ffffb103 == '\0') {
    maf_range_index_ffffb0fe = 2;
  }
  else {
    maf_range_index_ffffb0fe = 3;
  }
  return &maf_band_high_ffffb103;
}


