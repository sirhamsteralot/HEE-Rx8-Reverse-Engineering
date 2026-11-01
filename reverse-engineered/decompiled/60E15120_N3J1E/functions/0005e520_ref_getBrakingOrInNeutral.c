/* ROM address: 0x0005e520; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005cd2c (104 bytes). Names prefixed ref_
   are inherited hypotheses.
   
   [WIRING REVIEW 2026-09-08]
   Harness context: manual-transmission neutral switch is PCM 2O and opens in neutral (pp18-19).
   Brake switch is PCM 4P (p10). Input electrical polarity at the MCU and the interpretation of
   internal flags remain unverified. */

void ref_getBrakingOrInNeutral(void)

{
  undefined1 *puVar1;
  
  DAT_ffffd388 = inferred_ram_ad18_ffffad18_ffffad18 == '\x01';
  if (inferred_ram_bf3c_ffffbf3c_ffffbf3c == '\x01') {
    DAT_ffffd388 = DAT_ffffd388 + '\x04';
  }
  if (inferred_ram_bf9c_ffffbf9c_ffffbf9c == '\x01') {
    DAT_ffffd388 = DAT_ffffd388 + ' ';
  }
  if (inferred_ram_b53b_ffffb53b_ffffb53b == '\x01') {
    DAT_ffffd388 = DAT_ffffd388 + '@';
  }
  DAT_ffffd389 = 0;
  if (DAT_ffffb534 == '\x01') {
    puVar1 = &DAT_0007df1a;
    DAT_ffffd38a = 0x65;
  }
  else {
    puVar1 = &DAT_0007df1b;
    DAT_ffffd38a = 5;
  }
  DAT_ffffd38b = *puVar1;
  return;
}


