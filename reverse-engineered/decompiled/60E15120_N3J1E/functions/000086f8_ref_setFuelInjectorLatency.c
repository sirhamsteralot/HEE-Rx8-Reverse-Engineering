/* [ADDITIONAL SOURCE REVIEW]
 * set_fuel_injector_latency [high]: param_1 ch 0/1/2 -> a094/a0a0, a098/a0a4, a09c/a0a8 (latency value + mirror pair per channel); called by injector_latency_cal_lookup (0x2ff78) with ch0 = secondary, ch1/2 = primary.
 * RAM 0xffffa094 injector_latency_ch0 (float): Latency channel 0 (secondary) value; pair a0a0 mirror; read in injector_pulse_set_channel (0x8a68) pulse = a094[ch] + (a010[ch*0x18]>>4).
 * RAM 0xffffa098 injector_latency_ch1 (float): Latency channel 1 (primary); pair a0a4 mirror.
 * RAM 0xffffa09c injector_latency_ch2 (float): Latency channel 2 (primary); pair a0a8 mirror.
 * RAM 0xffffa0a0 injector_latency_ch0_mirror (float): Mirror of a094 written by the same call.
 * RAM 0xffffa0a4 injector_latency_ch1_mirror (float): Mirror of a098.
 * RAM 0xffffa0a8 injector_latency_ch2_mirror (float): Mirror of a09c.
 */
/* ROM address: 0x000086f8; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000086f8 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

int set_fuel_injector_latency(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    injector_latency_ch0_ffffa094 = param_2;
    injector_latency_ch0_mirror_ffffa0a0 = param_2;
  }
  if (param_1 == 1) {
    injector_latency_ch1_ffffa098 = param_2;
    injector_latency_ch1_mirror_ffffa0a4 = param_2;
  }
  if (param_1 == 2) {
    injector_latency_ch2_ffffa09c = param_2;
    injector_latency_ch2_mirror_ffffa0a8 = param_2;
  }
  return param_1;
}


