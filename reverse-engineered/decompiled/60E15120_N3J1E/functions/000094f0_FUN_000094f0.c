/* [ADDITIONAL SOURCE REVIEW]
 * pedal_adc_raw_to_volts [high]: AN4/AN5 raw (0xffff9eec/0xffff9eee from the 0x6884 sweep) range-checked against pool words 0x6eeb0=0xf5c3 (upper) / 0x6eeb4=0x11ec (lower), faults 0xffffa110/a111; a108 = 0.0f (0x6eec0) + raw * 6.341f (0x6eeb8=0x40cae979) * 7.6294e-05f; a10c = 3.488f (0x6eec4=0x405f3b64) + raw * 6.341 * 7.6294e-05. Called from 0x60c8 ref_getSensorStuff__ (pool 0x6250).
 * RAM 0xffff9eec adc_an4_pedal_raw (uint16): ADDR4H (0xfffff808) latched here by the 0x6884 ADC sweep (pool 0x6a1c=0xffff9ee4 base, +2n); read by 0x18f60 (pool 0x19058=0xffff9eec) into a9c4 (pool 0x1904a). Pedal APP1 raw. Harness: accelerator pedal sensor terminals 4X/5AE/5C/4Y/5AB/5F (B1-14 A-F); pin->terminal is board routing.
 * RAM 0xffff9eee adc_an5_pedal_raw (uint16): ADDR5H latched at 0xffff9eee by the 0x6884 sweep; pedal APP2 raw; feeds a9c6 via 0x18fa4.
 * RAM 0xffffa108 pedal_1_scaled_volts (float): a108 = 0.0f + AN4 raw * 6.341f (0x6eeb8) * 7.6294e-05f (0x94f0); range-checked [0x11ec, 0xf5c3) with faults a110/a111 -> DTC 0x66/0x67 (TP... pedal channel 1).
 */
/* ROM address: 0x000094f0; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000094f0 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * pedal_adc_raw_to_volts(void)

{
  ushort uVar1;
  undefined1 *puVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  ushort auStack_20 [2];
  
  DAT_ffffa112 = adc_an4_pedal_raw_ffff9eec;
  DAT_ffffa114 = adc_an5_pedal_raw_ffff9eee;
  puVar4 = &DAT_ffffa110;
  puVar5 = (undefined1 *)0x0;
  auStack_20[0] = adc_an4_pedal_raw_ffff9eec;
  auStack_20[1] = adc_an5_pedal_raw_ffff9eee;
  bVar3 = 0;
  puVar6 = puVar4;
  do {
    uVar9 = (uint)bVar3;
    uVar1 = auStack_20[uVar9];
    pcVar7 = &DAT_ffffa116 + bVar3;
    if ((uVar1 < *(ushort *)(&DAT_0006eeb0 + uVar9 * 2)) &&
       ((ushort)(&DAT_0006eeb4)[uVar9] <= uVar1)) {
      *pcVar7 = '\0';
      (&DAT_ffffa112)[uVar9] = auStack_20[uVar9];
    }
    else {
      if (*pcVar7 != -1) {
        *pcVar7 = *pcVar7 + '\x01';
      }
      if (2 < (byte)(&DAT_ffffa116)[bVar3]) {
        (&DAT_ffffa112)[uVar9] = auStack_20[uVar9];
      }
    }
    iVar8 = (uint)bVar3 * 4;
    (&pedal_1_scaled_volts_ffffa108)[bVar3] =
         *(float *)(&DAT_0006eec0 + iVar8) +
         (float)(&DAT_ffffa112)[uVar9] * *(float *)(&DAT_0006eeb8 + iVar8) * 7.6293945e-05;
    if (*(ushort *)(&DAT_0006eeb0 + uVar9 * 2) < auStack_20[uVar9]) {
      (&DAT_ffffa110)[bVar3] = 1;
      puVar2 = &DAT_ffffa110;
    }
    else {
      puVar2 = puVar5;
      if (*(ushort *)((int)auStack_20 + (int)puVar5) < *(ushort *)((int)&DAT_0006eeb4 + (int)puVar5)
         ) {
        *puVar4 = 2;
      }
      else {
        *puVar6 = 0;
      }
    }
    bVar3 = bVar3 + 1;
    puVar6 = puVar6 + 1;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 2;
  } while (bVar3 < 2);
  return puVar2;
}


