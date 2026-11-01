/* ROM address: 0x00060378; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ec68 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_setFaultEvalState_(void)

{
  uint uVar1;
  
  uVar1 = 1;
  if (DAT_ffffd1ad == '\x01') {
    uVar1 = 3;
  }
  if ((vehicle_inputs_pfdr_latch_ffff9ec8 & 1) == 0) {
    uVar1 = uVar1 | 4;
  }
  if (DAT_ffffd198 == '\x01') {
    uVar1 = uVar1 | 8;
  }
  return uVar1;
}


