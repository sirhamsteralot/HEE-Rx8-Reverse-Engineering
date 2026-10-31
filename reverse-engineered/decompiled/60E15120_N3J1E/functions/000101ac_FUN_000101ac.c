/* ROM address: 0x000101ac; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000101b0 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_000101ac(char param_1)

{
  float fVar1;
  
  fVar1 = injector_latency_secondary_ffffbe40;
  if ((((param_1 != '\0') && (param_1 != '\x03')) && (fVar1 = injector_latency_primary_ffffbe44, param_1 != '\x01')) &&
     (((param_1 != '\x02' && (param_1 != '\x04')) && (param_1 != '\x05')))) {
    fVar1 = 0.0;
  }
  return (int)(fVar1 / 0.25);
}


