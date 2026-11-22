/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffad61 tp_plausibility_fault_b (uint8): Set by 0x1bd9e; NOT(engine running && no cc98/cc99/b4f7/b4fb/b4fd && !873c) in 0x1ba20; read by 0x48cc0/0x487d6.
 */
/* ROM address: 0x0001bd9e; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001c84e (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0001bd9e(void)

{
  tp_plausibility_fault_b_ffffad61 = 1;
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff80a2,1);
  ref_updateMemoryAtAddress_float_VAL_ADDR(0x41a00000,&DAT_ffff8094);
  ref_updateMemoryAtAddress_float_VAL_ADDR(0x41a00000,&DAT_ffff80a4);
  return;
}


