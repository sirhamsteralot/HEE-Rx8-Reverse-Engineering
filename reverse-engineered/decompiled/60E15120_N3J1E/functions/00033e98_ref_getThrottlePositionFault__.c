/* [ADDITIONAL SOURCE REVIEW]
 * plate_range_high_fault [high]: c108 = 1 when ad48 (plate % of 84) >= 200.0f (ROM 0x79be0=0x43480000), clear hysteresis 196.48 = 200.0 - 3.52f (ROM 0x79be4=0x406147ae); pools 0x33f6a=0xad48, 0x33f6c=0xc108. Called from fueling_main_task 0x20e40; consumers 0x33dc8/0x34230 kill accel enrichment.
 * RAM 0xffffc108 tp_range_high_fault (uint8): Set by 0x33e98 when plate percent ad48 >= 200.0 (hyst 196.48); consumers 0x33dc8/0x34230 zero the accel-enrichment accumulators c0c8/c104.
 */
/* ROM address: 0x00033e98; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000345c4 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void plate_range_high_fault(void)

{
  if (196.48 <= inferred_ram_ad48_ffffad48_ffffad48) {
    if (200.0 <= inferred_ram_ad48_ffffad48_ffffad48) {
      tp_range_high_fault_ffffc108 = 1;
    }
  }
  else {
    tp_range_high_fault_ffffc108 = 0;
  }
  return;
}


