/* ROM address: 0x00056890; body bytes: 36; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f10c. Table purpose inferred from
   neighboring code. */

void diag22_pid0000_pids_supported_01_20(char param_1)

{
  diag_append_u16_be((int)param_1,0xbe1f);
  diag_append_u16_be((int)param_1,0xbe1fe813);
  return;
}


