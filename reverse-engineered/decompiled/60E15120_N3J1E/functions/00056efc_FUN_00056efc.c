/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1169_ram_807c_scaled [medium]: dispatch record 0x5f370 -> handler verified in ROM bytes + function_index; 0x56efc: readFloat(ffff807c, default 15)/25*7.63e-05
 * RAM 0xffff807c inferred_ram_807c_ffff807c (float): PID 0x1169, default 15.0
 */
/* ROM address: 0x00056efc; body bytes: 52; decompiled */

/* Function candidate recovered from ROM pointer at 5f378 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1169_ram_807c_scaled(char param_1)

{
  undefined4 uVar1;
  float fVar2;
  
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&inferred_ram_807c_ffff807c_ffff807c);
  uVar1 = rx8_encode_u16_affine_saturate((fVar2 - 0.0) / 25.0,0x38a00000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


