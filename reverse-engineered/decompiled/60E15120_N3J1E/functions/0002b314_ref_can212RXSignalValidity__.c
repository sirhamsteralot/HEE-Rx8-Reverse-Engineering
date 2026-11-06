/* [ADDITIONAL SOURCE REVIEW]
 * can212_rx_signal_validity [high]: Validity timers for three 0x212 signals: when 0xffffbbf2/bbf3/bbf4 != -1 reload counters 0xffffbbe8/bbea/bbec = 0x1f, else count down; a signal is stale when its counter reaches 0. Called from 0x2a2ae via pool 0x2a468.
 */
/* ROM address: 0x0002b314; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002ba68 (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 can212_rx_signal_validity(void)

{
  if (DAT_ffffbbf2 == -1) {
    if (DAT_ffffbbe8 != 0) {
      DAT_ffffbbe8 = DAT_ffffbbe8 + -1;
    }
  }
  else {
    DAT_ffffbbe8 = 0x1f;
  }
  if (DAT_ffffbbf3 == -1) {
    if (DAT_ffffbbea != 0) {
      DAT_ffffbbea = DAT_ffffbbea + -1;
    }
  }
  else {
    DAT_ffffbbea = 0x1f;
  }
  if (DAT_ffffbbf4 == -1) {
    if (DAT_ffffbbec != 0) {
      DAT_ffffbbec = DAT_ffffbbec + -1;
    }
  }
  else {
    DAT_ffffbbec = 0x1f;
  }
  return 0xffff;
}


