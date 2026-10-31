/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffa37e knock_ignition_threshold_a (uint16): Threshold A (default 94; = c090 from 0x336c4 via 0xc0f0); used by 0xc7ba coil outputs; the 0x33970 attack condition reads c090 directly (same raw value).
 * RAM 0xffffa37c knock_ignition_threshold_b (uint16): Threshold B (default 193; = c092); used by 0xc7ba coil outputs.
 * RAM 0xffff9f88 crank_period_accumulator (float): Sum of DAT_ffff9fd0[] periods; RPM denominator (ISR 0x803e); used by 0xc7ba coil scaling.
 */
/* ROM address: 0x0000c7ba; body bytes: 208; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000c7ba (208 bytes). Names prefixed ref_
   are inherited hypotheses.
   
   [WIRING REVIEW 2026-09-08]
   Harness context: diagram p10 identifies four ignition trigger wires: leading front 2AA, trailing
   front 2AD, leading rear 2Z, trailing rear 2AC. Firmware output/channel ordering is not confirmed
   by the diagram. */

void ref_setupCoilOutputs(void)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  float fVar5;
  float fVar6;
  undefined4 local_10 [2];
  
  DAT_ffff9f34 = DAT_ffff9f34 & 0xbf | 0x40;
  sci0_configure_sync_and_exchange_command();
  fVar5 = (float)knock_ignition_threshold_a_ffffa37e * ((float)crank_period_accumulator_ffff9f88 / 1152.0);
  if (2.1474836e+09 <= fVar5) {
    fVar5 = fVar5 - 4.2949673e+09;
  }
  fVar6 = (float)knock_ignition_threshold_b_ffffa37c * ((float)crank_period_accumulator_ffff9f88 / 1152.0);
  sVar4 = (short)((uint)((int)fVar5 + DAT_ffff9f9c) >> 4);
  if (2.1474836e+09 <= fVar6) {
    fVar6 = fVar6 - 4.2949673e+09;
  }
  sVar3 = (short)((uint)(int)fVar6 >> 4) + sVar4;
  ref_setSR_PARAM(local_10,0xe0);
  sVar2 = ATUII_TCNT2A_W;
  sVar2 = sVar2 + 3;
  if (((short)(sVar4 - sVar2) < 0) && (sVar4 = sVar2, (short)(sVar3 - sVar2) < 0)) {
    sVar3 = sVar2;
  }
  ATUII_OCR2E_W = sVar4;
  ATUII_GR2E_W = sVar3;
  FUN_0000a8a4(0xfffff658,0xffff);
  ATUII_TSR8_W = 0xefff;
  uVar1 = ATUII_TIER8_W;
  ATUII_TIER8_W = uVar1 & 0xefff | 0x1000;
  FUN_00002064(local_10[0]);
  return;
}


