/* [ADDITIONAL SOURCE REVIEW]
 * set_open_loop_flag [high]: Inherited name ref_setClosedLoopBool is a misnomer (polarity): sets b12c = (b12a != 0), i.e. the OPEN-loop flag; b12c blocks closed loop in 0x1c13c and selects open-loop targets in 0x1ee4a.
 * RAM 0xffffb12a open_loop_request (uint8): Set by 0x1f0c4 when load/throttle exceed the closed-loop fuelling thresholds; consumed by 0x1ee30.
 */
/* ROM address: 0x0001ee30; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001f890 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

void set_open_loop_flag(void)

{
  open_loop_active_ffffb12c = open_loop_request_ffffb12a != '\0';
  return;
}


