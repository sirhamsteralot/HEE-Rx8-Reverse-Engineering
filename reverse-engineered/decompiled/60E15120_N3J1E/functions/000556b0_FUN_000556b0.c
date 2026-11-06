/* [ADDITIONAL SOURCE REVIEW]
 * diag_read_90fc [medium]: PID 0x31: ffff90fc
 * RAM 0xffff90fc inferred_ram_90fc_ffff90fc (float): PID 0x31
 */
/* ROM address: 0x000556b0; body bytes: 30; decompiled */

void candidate_diag_read_90fc(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&inferred_ram_90fc_ffff90fc_ffff90fc);
  rx8_encode_u16_affine_saturate(uVar1,0x3f800000,uVar2);
  return;
}


