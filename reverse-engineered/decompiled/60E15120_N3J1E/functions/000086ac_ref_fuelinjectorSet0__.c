/* [ADDITIONAL SOURCE REVIEW]
 * injector_zero_offset_set [medium]: param_1 ch 0/1/2 -> a0ac/a0b8, a0b0/a0bc, a0b4/a0c0 (zero/offset pair per channel); caller 0x10208 ref_setAllInjectorto0_.
 * RAM 0xffffa0ac injector_zero_offset_ch0 (float): Zero/offset channel 0; pair a0b8 mirror; caller 0x10208 ref_setAllInjectorto0_.
 * RAM 0xffffa0b0 injector_zero_offset_ch1 (float): Zero/offset channel 1; pair a0bc.
 * RAM 0xffffa0b4 injector_zero_offset_ch2 (float): Zero/offset channel 2; pair a0c0.
 * RAM 0xffffa0b8 injector_zero_offset_ch0_mirror (float): Mirror of a0ac.
 * RAM 0xffffa0bc injector_zero_offset_ch1_mirror (float): Mirror of a0b0.
 * RAM 0xffffa0c0 injector_zero_offset_ch2_mirror (float): Mirror of a0b4.
 */
/* ROM address: 0x000086ac; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000086ac (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

int injector_zero_offset_set(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    injector_zero_offset_ch0_ffffa0ac = param_2;
    injector_zero_offset_ch0_mirror_ffffa0b8 = param_2;
  }
  if (param_1 == 1) {
    injector_zero_offset_ch1_ffffa0b0 = param_2;
    injector_zero_offset_ch1_mirror_ffffa0bc = param_2;
  }
  if (param_1 == 2) {
    injector_zero_offset_ch2_ffffa0b4 = param_2;
    injector_zero_offset_ch2_mirror_ffffa0c0 = param_2;
  }
  return param_1;
}


