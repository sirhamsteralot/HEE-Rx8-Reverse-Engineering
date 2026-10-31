/* ROM address: 0x0000c1f8; body bytes: 126; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000c1f8 (126 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_knockRelatedInit(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  
  knock_ignition_threshold_a_ffffa37e = 0x5e;
  knock_ignition_threshold_b_ffffa37c = 0xc1;
  knock_level_threshold_ffffa328 = 0x406c0000;
  knock_noise_excess_ffffa360 = 0x41200000;
  knock_threshold_command_base_ffffa364 = 0x42800000;
  knock_rotor_index_ffffa384 = 0xff;
  DAT_ffffa385 = 0;
  iVar4 = 0;
  puVar5 = &DAT_0007a750;
  high_rpm_10k_flag_ffffa386 = 0;
  knock_detected_ffffa324 = 0;
  knock_noise_filtered_ffffa32c = 0;
  iVar2 = 0;
  puVar3 = &knock_reference_voltage_latched_ffffa389;
  knock_baseline_slow_ffffa348 = 0;
  do {
    iVar4 = iVar4 + 1;
    *(undefined4 *)((int)&knock_noise_threshold_ffffa350 + iVar2) = 0x41200000;
    *(undefined4 *)((int)&knock_threshold_command_ffffa368 + iVar2) = 0x42800000;
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar3 = uVar1;
    *(undefined4 *)((int)&knock_level_running_ffffa334 + iVar2) = 0;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar4 < 2);
  return;
}


