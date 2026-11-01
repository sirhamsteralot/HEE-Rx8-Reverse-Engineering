/* ROM address: 0x00056d4c; body bytes: 50; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f2f8. Table purpose inferred from
   neighboring code. */

void candidate_diag22_pid0917_ram_ad5c_scaled_s16(char param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = rx8_decode_u16_affine(0x38a00000,0,(int)inferred_throttle_sensor_volts_ffffad5c_ffffad5c);
  uVar1 = candidate_diag_encode_s16_div(uVar1,0x3a800000,uVar2);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


