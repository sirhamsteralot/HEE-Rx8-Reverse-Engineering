/* [ADDITIONAL SOURCE REVIEW]
 * apv_counter_calc [high]: bf8a: 0 when bf8b==1 else saturating u8 increment — APV drive counter. | promoted to high (data/labels/60E15120_N3J1E/intake_labels.json/function_aliases)
 * RAM 0xffffbf8a apv_drive_counter (uint8): 0 when bf8b else saturating increment.
 */
/* ROM address: 0x00031f0a; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000323b2 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 apv_counter_calc(void)

{
  undefined4 uVar1;
  
  if (apv_direction_flag_ffffbf8b == '\x01') {
    apv_drive_counter_ffffbf8a = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = rx8_add_u8_saturate((int)apv_drive_counter_ffffbf8a,1);
    apv_drive_counter_ffffbf8a = (char)uVar1;
  }
  return uVar1;
}


