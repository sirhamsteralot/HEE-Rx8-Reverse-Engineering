/* [ADDITIONAL SOURCE REVIEW]
 * fan_output_gpio [high]: Fan relay GPIO output: PEDR_W 0xfffff754 bit 0x800 (PE11, SH7055F pkg pin 21) from 0x5c724(0xffffbda1) and bit 0x10 (PE4, pkg pin 12) from 0x5c648(0xffffbda2), each via ref_setRegister_REG_BIT_VAL 0x4bbc under mask 0xe0 (ref_setSR_PARAM 0x2054). Pool words: 0x2f240=0xe0, 0x2f242=0xf754, 0x2f244=0xbda1, 0x2f246=0x800, 0x2f248=0xbda2, 0x2f24c=0x2054, 0x2f250=0x4bbc, 0x2f254=0x2064, 0x2f258=0x5c724, 0x2f25c=0x5c648. The PE4 mask 0x10 is mov #0x10 at 0x2f222, not a pool word. PEDR_W at symbols.tsv 0xfffff754. Harness terminals: cooling fan relay 5X/5AD (pinout v3).
 * RAM 0xffffbda1 fan_low_speed_cmd (uint8): Fan 1 (low-speed relay) command computed by 0x2f51a (coolant 94/97 C hysteresis, engine-off/APV/SSV and A/C conditions, DTC gates); written to PEDR_W 0xfffff754 bit 0x800 (PE11) by 0x2f188/0x2f1dc via diag override 0x5c724.
 * RAM 0xffffbda2 fan_high_speed_cmd (uint8): Fan 2 (high-speed relay) command computed by 0x2f65c (needs bda1 && counter bda8 > 0x5c plus coolant 98/101 C / load / vspeed / A/C conditions); written to PEDR_W bit 0x10 (PE4) by 0x2f188/0x2f1dc via diag override 0x5c648.
 */
/* ROM address: 0x0002f1dc; body bytes: 100; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002f694 (100 bytes). Names prefixed ref_
   are inherited hypotheses. */

void fan_output_gpio(void)

{
  undefined4 local_18;
  undefined4 uStack_14;
  char cStack_10;
  
  cStack_10 = candidate_fan1_diag_override((int)fan_low_speed_cmd_ffffbda1);
  ref_setSR_PARAM(&uStack_14,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff754,0x800,cStack_10 == '\x01');
  FUN_00002064(uStack_14);
  cStack_10 = candidate_fan2_diag_override((int)fan_high_speed_cmd_ffffbda2);
  ref_setSR_PARAM(&local_18,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff754,0x10,cStack_10 == '\x01');
  FUN_00002064(local_18);
  return;
}


