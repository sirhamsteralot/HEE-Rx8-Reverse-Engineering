/* [ADDITIONAL SOURCE REVIEW]
 * misfire_learn_hold_decay [medium]: If sector_parity_bank 0xffffb660 == 1 and DAT_ffffba04 != 0: DAT_ffffba04-- (learn-hold counter decays once per odd sector). Called from 0x287aa.
 * RAM 0xffffba04 misfire_learn_hold (uint8): Learn-hold counter: decremented by 0x27306 once per odd sector (b660==1); gates the learn 0x276ec (ba04!=0 && ba06==0) and the sustained gate 0x273d4.
 */
/* ROM address: 0x00027306; body bytes: 34; decompiled */

short candidate_misfire_learn_hold_decay(void)

{
  if (sector_parity_bank_ffffb660 == 1) {
    if (misfire_learn_hold_ffffba04 != 0) {
      misfire_learn_hold_ffffba04 = misfire_learn_hold_ffffba04 + -1;
    }
  }
  return sector_parity_bank_ffffb660;
}


