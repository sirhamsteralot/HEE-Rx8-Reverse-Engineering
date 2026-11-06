/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pide21c_cal_id_chunk_1 [high]: dispatch record 0x5f4f0 -> handler verified in ROM bytes + function_index; appends '1','8'
 */
/* ROM address: 0x00057506; body bytes: 22; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f4f0. Table purpose inferred from
   neighboring code. */

void diag22_pide21c_cal_id_chunk_1(char param_1)

{
  diag_append_u8((int)param_1,0x31);
  diag_append_u8((int)param_1,0x38);
  return;
}


