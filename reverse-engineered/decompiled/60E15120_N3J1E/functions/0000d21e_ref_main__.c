/* [ADDITIONAL SOURCE REVIEW]
 * main_task_software_reset_check [medium]: Was ref_main__ (referenced from the task area via pool 0x655c near 0x64f6): bsr 0xd262 (pools 0xd2dc=0xd934, 0xd2e0=0x9890) and 0xd28e (pools 0xd2e4=0xffffa3e8, 0xd2bc=0x450); if result != -1 and byte @0xffff9f8c (pool 0xd2d4=0xffff9f8c) != 1: SR = (SR & 0xff0f) | 0xf0 (pool 0xd2b8=0xff0f), jsr 0x4e0 (pool 0xd2d8=0x4e0) with r4=1 r5=result - software reset via the param!=0 branch of 0x4e0, which stores the cause byte at 0xffffdfa8; halt 0xd258.
 */
/* ROM address: 0x0000d21e; body bytes: 68; decompiled_with_warnings */

/* Unique exact-byte match to related 60E0FC00 function at 0000d21e (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint candidate_main_task_software_reset_check(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = ref_interestingCANSomething();
  if (uVar1 == 0xffffffff) {
    uVar1 = FUN_0000d28e();
  }
  uVar2 = uVar1;
  if ((uVar1 != 0xffffffff) && (uVar2 = (uint)DAT_ffff9f8c, uVar2 == 1)) {
    reset_handler_warm_cold_select(1,uVar1);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return uVar2;
}


