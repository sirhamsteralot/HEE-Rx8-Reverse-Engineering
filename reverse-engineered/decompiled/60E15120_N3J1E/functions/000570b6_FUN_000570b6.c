/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid17a6_ram_d1ac_scaled [medium]: dispatch record 0x5f400 -> handler verified in ROM bytes + function_index; decode_u8(128,0,ffffd1ac)/1000*0.1
 * RAM 0xffffd1ac inferred_ram_d1ac_ffffd1ac (uint8): PID 0x17a6 decode(128)/1000*0.1
 */
/* ROM address: 0x000570b6; body bytes: 56; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f400. Table purpose inferred from
   neighboring code. */

void candidate_diag22_pid17a6_ram_d1ac_scaled(char param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  fVar1 = (float)rx8_decode_u8_affine(0x43000000,0,(int)inferred_ram_d1ac_ffffd1ac_ffffd1ac);
  uVar2 = rx8_encode_u8_affine_saturate(fVar1 / 1000.0,0x3dcccccc,uVar2);
  diag_append_u8((int)param_1,uVar2);
  return;
}


