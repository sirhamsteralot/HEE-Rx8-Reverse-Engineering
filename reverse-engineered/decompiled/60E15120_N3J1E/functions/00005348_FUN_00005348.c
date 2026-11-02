/* ROM address: 0x00005348; body bytes: 22; decompiled_with_warnings */

/* Unique exact-byte match to related 60E0FC00 function at 00005348 (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

void fatal_interrupt_trap(undefined4 param_1)

{
  undefined1 auStack_8 [4];
  undefined4 uStack_4;
  
  uStack_4 = param_1;
  ref_setSR_PARAM(auStack_8,0xe0);
  fatal_trap_report_halt(uStack_4);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


