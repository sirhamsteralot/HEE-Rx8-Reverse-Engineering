/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): inferred_ram_a9bc_ffffa9bc_ffffa9bc; decode = raw * 0.5 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x000292f8; body bytes: 64; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00029ca0 (64 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_000292f8(void)

{
  undefined1 *puVar1;
  
  puVar1 = &DAT_00078c6c;
  if (candidate_idle_learn_flag_ffffcc91 < 3) {
    puVar1 = (undefined1 *)rx8_encode_u8_affine_saturate(inferred_ram_a9bc_ffffa9bc_ffffa9bc,0x3f000000,0);
    DAT_ffffbb02 = (byte)puVar1;
    if (200 < DAT_ffffbb02) {
      DAT_ffffbb02 = 200;
    }
  }
  else {
    DAT_ffffbb02 = 0xff;
  }
  return puVar1;
}


