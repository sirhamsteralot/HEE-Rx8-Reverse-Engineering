/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069244: Table 2D - 10 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069258: Table 2D - 11 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006926c: Table 2D - 12 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069280: Table 2D - 13 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069294: Table 2D - 14 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000692a8: Table 2D - 15 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * idle_air_correction_select [medium]: Selects idle air correction 0xffffa8cc/0xffffa8d0 from 2-D tables 0x69244/0x69258/0x6926c/0x69280/0x69294/0x692a8 by flags 0xffffbd69/0xffffb534/0xffffb53c/0xffffb540/0xffffbdb8; bd69==0 forces a8cc=0. Called from 0x167c0 via pool 0x16898.
 */
/* ROM address: 0x00016900; body bytes: 162; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00016704 (162 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * candidate_idle_air_correction_select(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 extraout_fr0;
  undefined4 extraout_fr0_00;
  undefined4 extraout_fr0_01;
  
  if (ac_clutch_on_ffffbd69 == '\0') {
    puVar1 = &DAT_ffffa8cc;
    DAT_ffffa8cc = 0;
  }
  else {
    if ((automatic_transmission_ffffb534 == '\x01') || (at_drive_range_engaged_ffffb53c == '\0')) {
      if (inferred_ram_bdb8_ffffbdb8_ffffbdb8 == '\0') {
        puVar2 = &tbl_table_2d_10_00069244;
      }
      else {
        puVar2 = &tbl_table_2d_11_00069258;
      }
      puVar1 = (undefined4 *)lookup_2d_descriptor_scaled(puVar2);
      DAT_ffffa8d0 = extraout_fr0;
    }
    else if (DAT_ffffb540 == '\x01') {
      if (inferred_ram_bdb8_ffffbdb8_ffffbdb8 == '\0') {
        puVar2 = &tbl_table_2d_12_0006926c;
      }
      else {
        puVar2 = &tbl_table_2d_13_00069280;
      }
      puVar1 = (undefined4 *)lookup_2d_descriptor_scaled(puVar2);
      DAT_ffffa8d0 = extraout_fr0_00;
    }
    else {
      puVar1 = (undefined4 *)(uint)DAT_ffffb53e;
      if (puVar1 == (undefined4 *)0x1) {
        if (inferred_ram_bdb8_ffffbdb8_ffffbdb8 == '\0') {
          puVar2 = &tbl_table_2d_14_00069294;
        }
        else {
          puVar2 = &tbl_table_2d_15_000692a8;
        }
        puVar1 = (undefined4 *)lookup_2d_descriptor_scaled(intake_air_temperature_ffffaddc,puVar2);
        DAT_ffffa8d0 = extraout_fr0_01;
      }
    }
    DAT_ffffa8cc = DAT_ffffa8d0;
  }
  return puVar1;
}


