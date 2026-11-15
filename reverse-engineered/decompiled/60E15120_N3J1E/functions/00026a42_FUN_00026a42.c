/* [ADDITIONAL SOURCE REVIEW]
 * misfire_event_count [high]: Per rotor bank (sector_parity_bank_ffffb660&1): passes DAT_ffffba24/25 and DAT_ffffba26/27 to 0x26b34 with counter addresses 0xffffb688/0xffffb68e (parity 1) or 0xffffb68a/0xffffb68c (parity 0); clears all on engine stop. Called from 0x287aa.
 * RAM 0xffffb688 misfire_counter_bank1_a (uint16): Per-rotor misfire event counters bumped by 0x26a42/0x26b34 when the event flags are set; bank1 pair 0xffffb688/0xffffb68c, bank0 pair 0xffffb68a/0xffffb68e; DAT_ffffb694 = any event this tick; consumed by 0x445ba (DTC evaluation).
 */
/* ROM address: 0x00026a42; body bytes: 94; decompiled */

undefined4 FUN_00026a42(void)

{
  short sVar1;
  short sVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  
  if (DAT_ffffd1c5 == '\x01') {
    misfire_counter_bank1_a_ffffb688 = 0;
    DAT_ffffb68a = 0;
    DAT_ffffb68c = 0;
    DAT_ffffb68e = 0;
    misfire_any_event_tick_ffffb694 = 0;
    return 1;
  }
  if ((sector_parity_bank_ffffb660 & 1) == 1) {
    sVar1 = -0x4974;
    sVar2 = -0x4978;
    cVar3 = misfire_event_flag_a_ffffba24;
    cVar4 = misfire_event_flag_b_ffffba26;
  }
  else {
    sVar1 = -0x4972;
    sVar2 = -0x4976;
    cVar3 = DAT_ffffba25;
    cVar4 = DAT_ffffba27;
  }
  uVar5 = FUN_00026b34((int)cVar3,(int)cVar4,(int)sVar2,(int)sVar1);
  return uVar5;
}


