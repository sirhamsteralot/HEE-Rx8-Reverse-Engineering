/* [ADDITIONAL SOURCE REVIEW]
 * fuel_pump_relay_drive_pe2 [medium]: Writes PEDR_W 0xfffff754 bit 0x4 (PE2, SH7055F pkg pin 9) = (DAT_ffffbdd8 == 1) via ref_setRegister_REG_BIT_VAL 0x4bbc under SR mask 0xe0. Raw-bin verified: pool 0x2f930=0xbdd8 (cell), 0x2f932=0xf754 (PEDR low half), 0x2f93c=0x4bbc (helper), mask mov #0x4 at 0x2f8b0, cmp/eq 0x1 at 0x2f8a2. Caller 0x2f948, itself reached from the start-up sequence FUN_0001102a (pool 0x11308, jsr at 0x11136). Harness candidate: fuel pump relay control 5P (with immobilizer) / 5L (without); chip-pin->terminal routing unresolved.
 * RAM 0xffffbdd8 fuel_pump_relay_request (uint8): Written by 0x2fc00: key_on 0xffffaa68 && (bdda < 0x1f || (injectors_off a42c && bde0) || bddc <= 0x3e); primed 1 by 0x2fbf0. Drives PE2 (pkg pin 9); harness candidate fuel pump relay control 5P/5L. Pool-anchored: 0x2fcce=0xbdd8, 0x2f930=0xbdd8.
 */
/* ROM address: 0x0002f890; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002fd48 (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 candidate_fuel_pump_relay_drive_pe2(void)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  ref_setSR_PARAM(local_8,0xe0);
  if (fuel_pump_relay_request_ffffbdd8 == '\x01') {
    ref_setRegister_REG_BIT_VAL(0xfffff754,4,1);
  }
  else {
    ref_setRegister_REG_BIT_VAL(0xfffff754,4,0);
  }
  uVar1 = FUN_00002064(local_8[0]);
  return uVar1;
}


