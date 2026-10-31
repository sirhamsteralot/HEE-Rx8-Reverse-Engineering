/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000183a0; body bytes: 648; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000186bc) */
/* WARNING: Removing unreachable block (ram,0x00018480) */
/* WARNING: Removing unreachable block (ram,0x0001858a) */
/* WARNING: Removing unreachable block (ram,0x000185d0) */
/* WARNING: Removing unreachable block (ram,0x00018596) */
/* WARNING: Removing unreachable block (ram,0x000185a6) */
/* WARNING: Removing unreachable block (ram,0x000185ae) */
/* WARNING: Removing unreachable block (ram,0x000185b8) */
/* WARNING: Removing unreachable block (ram,0x000185c4) */
/* WARNING: Removing unreachable block (ram,0x000185ca) */
/* WARNING: Removing unreachable block (ram,0x00018550) */
/* WARNING: Removing unreachable block (ram,0x00018560) */
/* WARNING: Removing unreachable block (ram,0x00018568) */
/* WARNING: Removing unreachable block (ram,0x00018572) */
/* WARNING: Removing unreachable block (ram,0x0001857e) */
/* WARNING: Removing unreachable block (ram,0x00018580) */
/* WARNING: Removing unreachable block (ram,0x000185cc) */
/* Unique exact-byte match to related 60E0FC00 function at 00018f9c (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000183a0(uint param_1)

{
  byte snapshot_DAT_ffffa959;
  uint uVar2;
  uint uVar3;
  
  snapshot_DAT_ffffa959 = DAT_ffffa959;
  DAT_ffffa950 = FUN_0005d5da(0);
  if (DAT_ffffa950 < 0x32) {
    uVar2 = (uint)(char)DAT_ffffa950;
  }
  else {
    uVar2 = (int)(char)DAT_ffffa950 + 0xce;
  }
  uVar3 = param_1 & 0xff;
  if (DAT_ffffa957 != DAT_ffffa950) {
    DAT_ffffa958 = 0;
    DAT_ffffa956 = '\0';
    if ((uVar2 & 0xff) != 0) {
      if (DAT_ffffa950 < 0x32) {
        if ((uVar3 == 0) || (uVar3 == 0xc)) {
          DAT_ffffa956 = '\x01';
        }
      }
      else if ((DAT_ffffa950 < 0x65) && ((uVar3 == 6 || (uVar3 == 0x12)))) {
        DAT_ffffa956 = '\x01';
      }
    }
  }
  if (DAT_ffffa95a != '\0') {
    DAT_ffffa95b = 0;
  }
  if (engine_stopped_latch_ffffa41c != '\x01') {
    if (DAT_ffffa956 == '\x01') {
      if (DAT_ffffa958 == 0) {
        FUN_000186d8(0xf,param_1);
      }
      else {
        DAT_ffffa951 = 0;
        DAT_ffffa953 = 0;
        DAT_ffffa952 = 0;
        DAT_ffffa954 = 0;
      }
      if (DAT_ffffa958 < (byte)(&DAT_0006eb1f)[uVar2 & 0xff]) {
        DAT_ffffa958 = rx8_add_u8_saturate((int)(char)DAT_ffffa958,1);
      }
      else {
        DAT_ffffa958 = 0;
      }
      DAT_ffffa957 = DAT_ffffa950;
      DAT_ffffa959 = 5;
    }
    else if (((DAT_ffffa6b7 == '\x01') || (DAT_ffffa6b8 == '\x01')) || (DAT_ffffa6b9 == '\x01')) {
      FUN_000186d8(0,param_1);
      DAT_ffffa959 = 2;
    }
    else {
      if ((((engine_speed_rpm_ffffb548 < 0.0) || (1200.0 <= engine_speed_rpm_ffffb548)) ||
          ((inferred_coolant_temperature_ffffa98c < -40.0 || ((120.0 <= inferred_coolant_temperature_ffffa98c || (inferred_throttle_position_ffffad44 < 0.0)))))) ||
         (125.0 <= inferred_throttle_position_ffffad44)) {
        if ((uVar3 == 0) || (uVar3 == 0xc)) {
          DAT_ffffa951 = 0;
          DAT_ffffa953 = 0;
        }
        if ((uVar3 == 6) || (uVar3 == 0x12)) {
          DAT_ffffa952 = 0;
          DAT_ffffa954 = 0;
        }
        DAT_ffffa959 = 0;
        DAT_ffffa95a = 0;
        return (uint)snapshot_DAT_ffffa959;
      }
      FUN_000186d8(0,param_1);
      DAT_ffffa959 = 1;
    }
    uVar2 = FUN_000186a0();
    return uVar2;
  }
  DAT_ffffa951 = 0;
  DAT_ffffa952 = 0;
  DAT_ffffa953 = 0;
  DAT_ffffa954 = 0;
  DAT_ffffa95a = 0;
  DAT_ffffa95b = 0;
  DAT_ffffa95c = 0;
  DAT_ffffa958 = 0;
  DAT_ffffa957 = 0;
  DAT_ffffa956 = 0;
  DAT_ffffa959 = 0;
  uVar2 = FUN_000186a0();
  return uVar2;
}


