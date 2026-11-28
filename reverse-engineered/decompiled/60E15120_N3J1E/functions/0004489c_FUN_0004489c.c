/* [ADDITIONAL SOURCE REVIEW]
 * misfire_threshold_check_load [high]: Same shape on the secondary flags DAT_ffffba26/27 with DAT_ffffcb94*DAT_ffffba54 < DAT_ffffba58 || DAT_ffffcb98*DAT_ffffba54 < DAT_ffffba50 (cb94/cb98 = Load Limit A/B lookups tbl 0x6ba0c/0x6ba18 from 0x44a9e); counters DAT_ffffcb7c/0xffffcb7e. Called from 0x287aa.
 * RAM 0xffffcb7c misfire_load_counter_a (uint16): Load-threshold counter bumped by 0x4489c; delayed to cb82 by 0x4493a, snapshotted to b690 by 0x26aa0.
 * RAM 0xffffcb7e misfire_load_counter_b (uint16): Second load-threshold counter (0x4489c); snapshotted to b692 by 0x26aa0 at ba9e==2000.
 */
/* ROM address: 0x0004489c; body bytes: 158; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000440b8 (158 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint misfire_threshold_check_load(void)

{
  uint in_r7;
  uint unaff_r12;
  
  if (DAT_ffffd1c5 == '\x01') {
    misfire_load_counter_a_ffffcb7c = 0;
    misfire_load_counter_b_ffffcb7e = 0;
  }
  if ((sector_parity_bank_ffffb660 & 1) == 0) {
    in_r7 = (uint)DAT_ffffba27;
    unaff_r12 = 1;
  }
  else if ((sector_parity_bank_ffffb660 & 1) == 1) {
    unaff_r12 = 0;
    in_r7 = (uint)misfire_event_flag_b_ffffba26;
  }
  in_r7 = in_r7 & 0xff;
  if (in_r7 == 1) {
    if ((misfire_threshold_load_a_ffffcb94 * misfire_deviation_d1_ffffba54 < misfire_deviation_d2_ffffba58) || (misfire_threshold_load_b_ffffcb98 * misfire_deviation_d1_ffffba54 < misfire_deviation_now_ffffba50)
       ) {
      in_r7 = unaff_r12 & 0xffff;
      (&misfire_event_flag_b_ffffba26)[in_r7] = 0;
    }
    else if (DAT_ffffd1c5 == '\0') {
      misfire_load_counter_a_ffffcb7c = rx8_add_u16_saturate((int)misfire_load_counter_a_ffffcb7c,1);
      in_r7 = rx8_add_u16_saturate((int)misfire_load_counter_b_ffffcb7e,1);
      misfire_load_counter_b_ffffcb7e = (short)in_r7;
    }
  }
  return in_r7;
}


