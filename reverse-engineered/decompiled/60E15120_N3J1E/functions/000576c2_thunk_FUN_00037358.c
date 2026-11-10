/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pidc116_dtc_state_machine [medium]: dispatch record 0x5f538 -> handler verified in ROM bytes + function_index; thunk to 0x37358: DTC state machine; sets DAT_ffffd1e8 response code
 */
/* ROM address: 0x000576c2; body bytes: 6; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f538. Table purpose inferred from
   neighboring code. */

void diag22_pidc116_dtc_state_machine(void)

{
  dtc_state_machine_step();
  return;
}


