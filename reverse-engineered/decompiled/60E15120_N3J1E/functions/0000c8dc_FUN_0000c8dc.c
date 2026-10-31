/* [ADDITIONAL SOURCE REVIEW]
 * knock_sensor_sci_command [high]: SCI front-end on ATU window: rotor alternation a383/a384, reference select by a386 (ROM 0x7a750/0x7a752), command-code mapping a368->a380/a381 (6/5/4/2/0 bands), send via update_serial_command_bits_3_to_5_and_send or sci0_configure_sync_and_exchange_command.
 * RAM 0xffffa384 knock_rotor_index (uint8): Rotor/channel index 0xff (init) or 0/1; alternates per ATU window in 0xc8dc.
 * RAM 0xffffa368 knock_threshold_command (float[2]): Per-rotor threshold command a368[0..1] = a364 + a360*2; mapped to command codes in 0xc8dc.
 * RAM 0xffffa387 knock_reference_voltage (uint8[2]): Per-channel reference bytes from ROM 0x7a750/0x7a752 selected by a386.
 * RAM 0xffffa380 knock_command_code_current (uint8): Current command code a380 sent over SCI.
 * RAM 0xffffa386 high_rpm_10k_flag (uint8): Set by 0xc3ce when raw RPM >= 10000; selects reference table 0x7a752 vs 0x7a750 (both 01 01 in this ROM).
 */
/* ROM address: 0x0000c8dc; body bytes: 334; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0000ca3a) */

void knock_sensor_sci_command(void)

{
  ushort uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  float fVar5;
  
  uVar2 = sh_raise_interrupt_mask_return_previous(0x90);
  uVar1 = ATUII_DSTR_W;
  if ((uVar1 & 0x1000) != 0) {
    FUN_0000a8a4(0xfffff658,0);
    knock_reference_adc_read();
  }
  ref_setSR(uVar2);
  if (DAT_ffffa385 == '\x01') {
    knock_rotor_index_ffffa384 = DAT_ffffa383;
  }
  bVar4 = DAT_ffffa383 + 1;
  if (1 < (byte)(DAT_ffffa383 + 1U)) {
    bVar4 = 0;
  }
  DAT_ffff9f34 = DAT_ffff9f34 & 0xbc | (&DAT_0000d90c)[bVar4];
  if (high_rpm_10k_flag_ffffa386 == '\0') {
    (&knock_reference_voltage_ffffa387)[bVar4] = (&DAT_0007a750)[bVar4];
  }
  else {
    (&knock_reference_voltage_ffffa387)[bVar4] = (&DAT_0007a752)[bVar4];
  }
  if (((&knock_reference_voltage_ffffa387)[bVar4] == '\x01') || ((&knock_reference_voltage_ffffa387)[bVar4] != '\x02')) {
    bVar3 = 0;
  }
  else {
    bVar3 = 4;
  }
  DAT_ffff9f34 = DAT_ffff9f34 & 0xfb | bVar3;
  fVar5 = (float)(&knock_threshold_command_ffffa368)[bVar4];
  if (fVar5 < 192.0) {
    if (fVar5 < 128.0) {
      if (fVar5 < 96.0) {
        if (fVar5 < 64.0) {
          knock_command_code_current_ffffa380 = '\x06';
        }
        else {
          knock_command_code_current_ffffa380 = '\x05';
        }
      }
      else {
        knock_command_code_current_ffffa380 = '\x04';
      }
    }
    else {
      knock_command_code_current_ffffa380 = '\x02';
    }
  }
  else {
    knock_command_code_current_ffffa380 = '\0';
  }
  (&knock_command_code_ffffa381)[bVar4] = knock_command_code_current_ffffa380;
  if (knock_command_code_current_ffffa380 != '\0') {
    if (knock_command_code_current_ffffa380 == '\x02') {
      update_serial_command_bits_3_to_5_and_send(&DAT_ffff9f34,8);
      return;
    }
    if (knock_command_code_current_ffffa380 == '\x04') {
      update_serial_command_bits_3_to_5_and_send(&DAT_ffff9f34,0x10);
      return;
    }
    if (knock_command_code_current_ffffa380 == '\x05') {
      update_serial_command_bits_3_to_5_and_send(&DAT_ffff9f34,0x18);
      return;
    }
    if (knock_command_code_current_ffffa380 == '\x06') {
      update_serial_command_bits_3_to_5_and_send(&DAT_ffff9f34,0x20);
      return;
    }
  }
  DAT_ffff9f34 = DAT_ffff9f34 & 199;
  sci0_configure_sync_and_exchange_command();
  return;
}


