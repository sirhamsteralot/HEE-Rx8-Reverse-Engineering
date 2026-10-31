/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b3f0: Table 2D - 235 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0004f444; body bytes: 204; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004d004 (204 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * ref_interestingFunc1(void)

{
  undefined1 *puVar1;
  float extraout_fr0;
  float fVar2;
  
  DAT_ffffcffc = (float)lookup_2d_descriptor_scaled(inferred_battery_voltage_ffffb590,&tbl_table_2d_235_0006b3f0);
  fVar2 = ((DAT_ffffcfa0 * DAT_ffffcffc) / 33.0) / 4.0;
  puVar1 = (undefined1 *)(uint)DAT_ffffcfbe;
  if ((((puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) && (DAT_ffffcffa == '\0')) &&
      (DAT_ffffcfa6 <= DAT_ffffcfaa)) || (DAT_ffffcff9 == '\n')) {
    DAT_ffffcff9 = '\x01';
    DAT_ffffcfd8 = fVar2;
  }
  else {
    if (puVar1 != (undefined1 *)((int)&vector_Poweron_Reset + 1)) {
      return puVar1;
    }
    if (DAT_ffffcfa6 <= DAT_ffffcfaa) {
      DAT_ffffcff9 = rx8_add_u8_saturate((int)DAT_ffffcff9,1);
      DAT_ffffcfd8 = DAT_ffffcfd8 + fVar2;
    }
  }
  if ((puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) &&
     (puVar1 = &DAT_0007d66d, DAT_ffffcff9 == '\n')) {
    puVar1 = (undefined1 *)rx8_decode_u8_affine(0x3f800000,0,10);
    DAT_ffffcfdc = DAT_ffffcfd8 / extraout_fr0;
  }
  return puVar1;
}


