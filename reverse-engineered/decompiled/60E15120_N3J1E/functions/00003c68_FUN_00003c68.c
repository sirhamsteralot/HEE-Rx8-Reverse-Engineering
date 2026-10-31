/* [ADDITIONAL SOURCE REVIEW]
 * os_dispatch_next_task [high]: Tail-calls 0x375c(ctrl, *(short*)(ctrl+6)).
 */
/* ROM address: 0x00003c68; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003c68 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void os_dispatch_next_task(int param_1)

{
  os_switch_to_task(param_1,(int)*(short *)(param_1 + 6));
  return;
}


