/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_c644 [high]: PID 0x3c: ffffc644*0.1-40 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 * RAM 0xffffc644 fuel_correction_sum_ffffc644 (float): PID 0x3c: x*0.1-40; ROADMAP group C names this cell fuel_correction_sum
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): fuel_correction_sum_ffffc644_ffffc644; decode = raw * 0.09999999404 + (-40) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x0005571a; body bytes: 24; decompiled */

undefined4 diag_encode_c644(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(fuel_correction_sum_ffffc644_ffffc644,0x3dcccccc,0xc2200000);
  return uVar1;
}


