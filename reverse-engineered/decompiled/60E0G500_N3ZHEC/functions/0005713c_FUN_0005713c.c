/* ROM address: 0x0005713c; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f918 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid000d_vehicle_speed_kmh(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_vss();
  diag_append_u8((int)param_1,uVar1);
  return;
}


