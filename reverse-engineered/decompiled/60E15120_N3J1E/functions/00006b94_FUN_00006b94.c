/* ROM address: 0x00006b94; body bytes: 128; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00006b94 (76 bytes). Names prefixed ref_
   are inherited hypotheses.
   
   [WIRING REVIEW 2026-09-08]
   Firmware fact: alternate ADC acquisition also writes RAM 0xffff9ef0 from register 0xfffff80c.
   Candidate APV input; the hardware diagram does not itself assign ADC channels. */

uint FUN_00006b94(void)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_ffff9f2b == 0) {
    return 0;
  }
  uVar1 = (uint)DAT_ffff9f2b;
  if (uVar1 == 0xc) {
    DAT_ffff9efa = ADDR11H_B;
    knock_sensor_adc_raw_ffff9ef8 = ADDR10H_B;
    DAT_ffff9ef6 = ADDR9H_B;
    DAT_ffff9ef4 = ADDR8H_B;
LAB_00006be0:
    DAT_ffff9ef2 = ADDR7H_B;
    adc6_raw_apv_position_ffff9ef0 = ADDR6H_B;
    DAT_ffff9eee = ADDR5H_B;
    DAT_ffff9eec = ADDR4H_B;
  }
  else {
    if (uVar1 == 8) goto LAB_00006be0;
    if (uVar1 != 4) {
      uVar2 = 1;
      if (uVar1 != 1) {
        DAT_ffff9f29 = 0;
        DAT_ffff9f2a = 0;
        return uVar1;
      }
      goto LAB_00006c0a;
    }
  }
  maf_adc_raw_ffff9eea = ADDR3H_B;
  DAT_ffff9ee8 = ADDR2H_B;
  DAT_ffff9ee6 = ADDR1H_B;
  uVar2 = (uint)DAT_ffff9ee6;
LAB_00006c0a:
  DAT_ffff9ee4 = ADDR0H_B;
  DAT_ffff9f2a = 0;
  DAT_ffff9f29 = 0;
  return uVar2;
}


