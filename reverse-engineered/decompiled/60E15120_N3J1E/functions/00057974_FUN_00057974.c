/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pidff44_ram_ce30_raw [medium]: dispatch record 0x5f5a4 -> handler verified in ROM bytes + function_index; raw DAT_ffffce30 u16
 * RAM 0xffffce30 inferred_ram_ce30_ffffce30 (uint16): PID 0xff44 raw
 */
/* ROM address: 0x00057974; body bytes: 6; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f5a4. Table purpose inferred from
   neighboring code. */

void diag22_pidff44_ram_ce30_raw(undefined4 param_1)

{
  diag_append_u16_be(param_1,(int)inferred_ram_ce30_ffffce30_ffffce30);
  return;
}


