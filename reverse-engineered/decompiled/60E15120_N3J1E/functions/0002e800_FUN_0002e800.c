/* [ADDITIONAL SOURCE REVIEW]
 * ac_clutch_relay_drive_pj7 [high]: Writes PJDR_W 0xfffff76c bit 0x80 (PJ7, pkg pin 183) = (DAT_ffffbd68 == 1) via 0x4bbc. Corrects the earlier 'fuel-pump relay candidate' note in reviews/intake_solenoids/README.md: 0xffffbd68 is set by ref_calculateACClutchOn__ 0x2e89c (ac_clutch_on 0xffffbd69, rpm 0xffffb548 thresholds 600.0/7800.0 at ROM 0x774c0/0x774c4), i.e. the A/C compressor clutch. Harness candidate: A/C relay 5AA.
 * RAM 0xffffbd68 ac_clutch_relay_drive (uint8): Set by ref_calculateACClutchOn__ 0x2e89c from ac_clutch_on 0xffffbd69 with rpm 0xffffb548 thresholds (pools 0x2e968=0xb548, 0x2e96a=0xbd68, 0x2e96c=0xbd69; floats 600.0/7800.0 at ROM 0x774c0/0x774c4). Drives PJ7 (pkg pin 183); harness candidate A/C relay 5AA - not the fuel pump.
 */
/* ROM address: 0x0002e800; body bytes: 64; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002ecb8 (64 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0002e800(void)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  ref_setSR_PARAM(local_8,0xe0);
  if (DAT_ffffbd68 == '\x01') {
    ref_setRegister_REG_BIT_VAL(0xfffff76c,0x80);
  }
  else {
    ref_setRegister_REG_BIT_VAL(0xfffff76c,0x80,0);
  }
  uVar1 = FUN_00002064(local_8[0]);
  return uVar1;
}


