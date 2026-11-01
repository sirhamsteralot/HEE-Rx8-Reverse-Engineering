/* ROM address: 0x00057168; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f930 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid000f_intake_air_temp_c(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_iat();
  diag_append_u8((int)param_1,uVar1);
  return;
}


