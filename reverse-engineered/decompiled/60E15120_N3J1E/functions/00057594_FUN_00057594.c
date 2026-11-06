/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1710_sensor_snapshot_7byte [medium]: dispatch record 0x5f520 -> handler verified in ROM bytes + function_index; 7 appends from DAT_ffff9150/9158/9160/... (temps/voltages), encode u8 affine
 * RAM 0xffff9150 inferred_sensor_block_ffff9150 (float[7]): PID 0x1710 7-byte snapshot block 0xffff9150-0xffff917e + 0xffffd38a/d38b
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): uVar4; decode = raw * 0.1953125 + (-25) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00057594; body bytes: 288; decompiled */

/* Function candidate recovered from ROM pointer at 5f528 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid1710_sensor_snapshot_7byte(undefined4 param_1)

{
  char cVar2;
  uint uVar1;
  byte bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar7 = 0;
  uVar4 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&inferred_sensor_block_ffff9150_ffff9150);
  uVar5 = 0x3f800000;
  uVar4 = rx8_encode_u8_affine_saturate(uVar4,0x3f800000,uVar7);
  diag_append_u8(param_1,uVar4);
  uVar4 = ref_readValue_float_DEFAULTVAL_ADDRESS(uVar7,&DAT_ffff9158);
  uVar4 = rx8_encode_u8_affine_saturate(uVar4,uVar5,0xc2200000);
  diag_append_u8(param_1,uVar4);
  uVar4 = ref_readValue_float_DEFAULTVAL_ADDRESS(uVar7,&DAT_ffff9160);
  uVar5 = 0xc1c80000;
  uVar6 = 0x3e480000;
  uVar4 = rx8_encode_u8_affine_saturate(uVar4,0x3e480000,0xc1c80000);
  diag_append_u8(param_1,uVar4);
  uVar4 = ref_readValue_float_DEFAULTVAL_ADDRESS(uVar7,&DAT_ffff9168);
  uVar4 = rx8_encode_u8_affine_saturate(uVar4,uVar6,uVar5);
  diag_append_u8(param_1,uVar4);
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff9174,1);
  bVar3 = cVar2 == '\x01';
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff9176,1);
  if (cVar2 == '\x01') {
    bVar3 = bVar3 | 2;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff9178,0);
  if (cVar2 == '\x01') {
    bVar3 = bVar3 | 4;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff917a,0);
  if (cVar2 == '\x01') {
    bVar3 = bVar3 | 8;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff917c,0);
  if (cVar2 == '\x01') {
    bVar3 = bVar3 | 0x10;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff917e,0);
  if (cVar2 == '\x01') {
    bVar3 = bVar3 | 0x20;
  }
  uVar4 = diag22_subpid_supported_mask(bVar3,5);
  diag_append_u8(param_1,uVar4);
  uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff9170,0xff);
  diag_append_u8(param_1,uVar1 & (int)DAT_ffffd38a);
  uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff9172,0xff);
  diag_append_u8(param_1,uVar1 & (int)DAT_ffffd38b);
  return;
}


