/* [ADDITIONAL SOURCE REVIEW]
 * misfire_threshold_check_rpm [high]: Per rotor bank: if event flag DAT_ffffba24/25 set, clears it when DAT_ffffcb8c*DAT_ffffba44 < DAT_ffffba48 || DAT_ffffcb90*DAT_ffffba44 < DAT_ffffba40 (cb8c/cb90 = RPM lookups tbl 0x6b9f4/0x6ba00 from 0x44a78; ba44/ba48 = delayed DAT_ffffba40), else bumps counters DAT_ffffcb78/0xffffcb7a. Called from 0x287aa.
 * RAM 0xffffcb78 misfire_rpm_counter_a (uint16): Primary rpm-threshold counter bumped by 0x447e2 while the event flag survives the cb8c/cb90 threshold products; delayed to cb80 by 0x4493a, snapshotted to b690 by 0x26aa0.
 * RAM 0xffffcb7a misfire_rpm_counter_b (uint16): Second rpm-threshold counter (0x447e2); snapshotted to b692 by 0x26aa0 at ba9e==2000.
 */
/* ROM address: 0x000447e2; body bytes: 152; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00043ffe (152 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint misfire_threshold_check_rpm(void)

{
  uint uVar1;
  undefined2 *puVar2;
  uint in_r7;
  
  if (DAT_ffffd1c5 == '\x01') {
    misfire_rpm_counter_a_ffffcb78 = 0;
    misfire_rpm_counter_b_ffffcb7a = 0;
  }
  puVar2 = &sector_parity_bank_ffffb660;
  if ((sector_parity_bank_ffffb660 & 1) == 0) {
    puVar2 = (undefined2 *)(int)DAT_ffffba25;
    in_r7 = 1;
  }
  else if ((sector_parity_bank_ffffb660 & 1) == 1) {
    puVar2 = (undefined2 *)(int)misfire_event_flag_a_ffffba24;
    in_r7 = 0;
  }
  uVar1 = (uint)puVar2 & 0xff;
  if (uVar1 == 1) {
    if ((misfire_threshold_rpm_a_ffffcb8c * misfire_excess_deviation_delayed_ffffba44 < DAT_ffffba48) || (misfire_threshold_rpm_b_ffffcb90 * misfire_excess_deviation_delayed_ffffba44 < misfire_excess_deviation_ffffba40)
       ) {
      uVar1 = in_r7 & 0xffff;
      (&misfire_event_flag_a_ffffba24)[uVar1] = 0;
    }
    else if (DAT_ffffd1c5 == '\0') {
      misfire_rpm_counter_a_ffffcb78 = rx8_add_u16_saturate((int)misfire_rpm_counter_a_ffffcb78,1);
      uVar1 = rx8_add_u16_saturate((int)misfire_rpm_counter_b_ffffcb7a,1);
      misfire_rpm_counter_b_ffffcb7a = (short)uVar1;
    }
  }
  return uVar1;
}


