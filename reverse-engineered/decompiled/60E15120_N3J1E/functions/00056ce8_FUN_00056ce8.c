/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0914_ram_a9c4_scaled_s16 [high]: dispatch record 0x5f2e0 -> handler verified in ROM bytes + function_index; 0x54884(a9c4) helper = (x-p3)/p2+0.5 s16 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x00056ce8; body bytes: 50; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f2e0. Table purpose inferred from
   neighboring code. */

void diag22_pid0914_ram_a9c4_scaled_s16(char param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = rx8_decode_u16_affine(0x38a00000,0,(int)inferred_pedal_volts_ffffa9c4_ffffa9c4);
  uVar1 = diag_encode_s16_div(uVar1,0x3a800000,uVar2);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


