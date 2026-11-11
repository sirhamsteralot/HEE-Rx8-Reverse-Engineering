/* [ADDITIONAL SOURCE REVIEW]
 * diag_read_90fc [high]: PID 0x31: ffff90fc | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 * RAM 0xffff90fc inferred_ram_90fc_ffff90fc (float): PID 0x31
 */
/* ROM address: 0x000556b0; body bytes: 30; decompiled */

void diag_read_90fc(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&inferred_ram_90fc_ffff90fc_ffff90fc);
  rx8_encode_u16_affine_saturate(uVar1,0x3f800000,uVar2);
  return;
}


