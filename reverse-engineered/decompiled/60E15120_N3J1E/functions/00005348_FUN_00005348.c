/* [ADDITIONAL SOURCE REVIEW]
 * fatal_interrupt_trap [high]: Fatal trap for reserved/unexpected vectors: raises SR mask to 0xe0 (ref_setSR_PARAM), calls 0xa330(code), spins at 0x535a (disasm 0x5348-0x535c). 99 of 119 real-trampoline IVT handlers + vec 0-63 stubs 0x53a0-0x53c2 call it; the 20 real handlers incl. vec-231 0x5ef4 (harness-verified) do not.
 */
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


