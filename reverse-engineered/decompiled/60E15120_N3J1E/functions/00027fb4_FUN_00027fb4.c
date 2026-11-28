/* [ADDITIONAL SOURCE REVIEW]
 * misfire_event_arm [high]: DAT_ffffba28 = lookup_2d_scaled(rpm, tbl 0x6a6b8); per rotor bank (DAT_ffffb660&1) sets (&DAT_ffffba24)[parity] = 1 when DAT_ffffb53a==1 && engine_load >= DAT_ffffba28 && DAT_ffffb69c==1 && DAT_ffffb6c6==1 && DAT_ffffba40 > DAT_ffffba78 (cleared otherwise). Arms the per-rotor misfire event flag. Called from 0x287aa.
 * RAM 0xffffba24 misfire_event_flag_a (uint8[2]): Per-rotor (sector parity) misfire event flags: set by 0x27fb4/0x28022 when the excess deviation DAT_ffffba40 exceeds DAT_ffffba78 with the cell learned; checked/cleared by 0x447e2; counted by 0x26a42 into 0xffffb688-0xffffb68e; DTC-evaluated by 0x445ba -> P0300/P0301/P0302.
 * RAM 0xffffba28 misfire_load_floor (float): DAT_ffffba28 = lookup_2d_scaled(rpm, tbl 0x6a6b8 [17 cells, 700..8500 rpm]); load floor for the primary event arm 0x27fb4 (bypassed in neutral b53a==1). Pool 0x28074=0xffffba28.
 */
/* ROM address: 0x00027fb4; body bytes: 110; decompiled */

char misfire_event_arm(void)

{
  ushort uVar1;
  char cVar2;
  
  uVar1 = sector_parity_bank_ffffb660 & 1;
  misfire_load_floor_ffffba28 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&DAT_0006a6b8);
  if ((((DAT_ffffb53a != '\x01') && (cVar2 = DAT_ffffb53a, engine_load_ffffc0b4 < misfire_load_floor_ffffba28)) ||
      (cVar2 = misfire_supply_enable_ffffb69c, misfire_supply_enable_ffffb69c != '\x01')) ||
     ((cVar2 = misfire_cell_learned_ffffb6c6, misfire_cell_learned_ffffb6c6 != '\x01' || (misfire_excess_deviation_ffffba40 <= misfire_threshold_a_ffffba78)))) {
    (&misfire_event_flag_a_ffffba24)[uVar1] = 0;
  }
  else {
    cVar2 = '\x01';
    (&misfire_event_flag_a_ffffba24)[uVar1] = 1;
  }
  return cVar2;
}


