/* ROM address: 0x00006744; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00006744 (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

void vehicle_inputs_poll_pfdr_phdr(void)

{
  vehicle_inputs_pfdr_latch_ffff9ec8 = PFDR_W;
  vehicle_inputs_phdr_latch_ffff9eca = PHDR_W;
  vehicle_inputs_pfdr_prev_ffff9ed8 = vehicle_inputs_pfdr_latch_ffff9ec8;
  vehicle_inputs_phdr_prev_ffff9eda = vehicle_inputs_phdr_latch_ffff9eca;
  DAT_ffff9ecc = ref_getFromGPIO_(0);
  DAT_ffff9edc = DAT_ffff9ecc;
  DAT_ffff9ecd = ref_getFromGPIO_(1);
  DAT_ffff9edd = DAT_ffff9ecd;
  DAT_ffff9ede = ref_getFromGPIO_(2);
  DAT_ffff9ece = DAT_ffff9ede;
  DAT_ffff9ed4 = 0;
  DAT_ffff9ed0 = 0;
  return;
}


