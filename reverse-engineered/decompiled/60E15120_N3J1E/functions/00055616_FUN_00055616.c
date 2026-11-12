/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_b2f0 [high]: PID 0x2e: ffffb2f0*0.392157 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 * RAM 0xffffb2f0 inferred_ram_b2f0_ffffb2f0 (float): PID 0x2e
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): inferred_ram_b2f0_ffffb2f0_ffffb2f0; decode = raw * 0.3921568394 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00055616; body bytes: 22; decompiled */

undefined4 diag_encode_b2f0(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(inferred_ram_b2f0_ffffb2f0_ffffb2f0,0x3ec8c8c8,0);
  return uVar1;
}


