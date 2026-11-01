/* ROM address: 0x00057094; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f8dc and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0004_calculated_engine_load_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_read_calc_load_pct();
  diag_append_u8((int)param_1,uVar1);
  return;
}


