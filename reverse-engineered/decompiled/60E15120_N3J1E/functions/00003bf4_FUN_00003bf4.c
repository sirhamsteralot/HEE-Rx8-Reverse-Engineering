/* [ADDITIONAL SOURCE REVIEW]
 * os_context_switch [high]: Saves ctx ptr to ctrl+0xc, writes state 4, calls os_dispatch_next_task (0x3c68); called from 0x3db0 (ISR-exit wake) and 0x3854.
 */
/* ROM address: 0x00003bf4; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003bf4 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

void os_context_switch(int param_1,undefined4 param_2,char *param_3)

{
  undefined1 *puVar1;
  undefined1 local_44 [16];
  undefined1 local_34 [4];
  
  puVar1 = local_34;
  if (*param_3 == '\x04') {
    puVar1 = local_44;
  }
  **(undefined1 **)(param_3 + 4) = 4;
  *(undefined1 **)(param_1 + 0xc) = puVar1;
  os_dispatch_next_task();
  return;
}


