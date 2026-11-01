/* ROM address: 0x00056f8a; body bytes: 32; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f3a0. Table purpose inferred from
   neighboring code. */

void candidate_diag22_pid163e_ram_b074_scaled_s16(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = candidate_diag_encode_s16_div(inferred_trim_b074_ffffb074_ffffb074,0x39000000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


