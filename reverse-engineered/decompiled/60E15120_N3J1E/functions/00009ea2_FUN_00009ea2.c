/* [ADDITIONAL SOURCE REVIEW]
 * shutdown_wait_key_pin_then_halt [high]: Key-off wait/halt: SR = (SR & 0xff0f) | 0xf0 (pool 0x9f1c=0xff0f); ref_setSR_PARAM 0xe0 (pool 0x9f18=0xe0, jsr pool 0x9f28=0x2054); ref_setRegister_REG_BIT_VAL PFDR_W 0xfffff74e (pool 0x9f1a=0xf74e) mask 8 val 0 (r5=8 r6=0, jsr pool 0x9f2c=0x4bbc); loop 0x9ed0: busy-wait jsr 0x239c with r4=0x1388 (pools 0x9f40=0x239c, 0x9f1e=0x1388), WDT pulse jsr 0xa850 (pool 0x9f3c=0xa850), r0 = PFDR_W & 1 (r14=1) at 0x9ed8-0x9ee2; loops while bit0 == 0, bsr 0x9efe (masked halt) once bit0 == 1. Called from 0x252c2 via pool 0x253a8=0x9ea2.
 */
/* ROM address: 0x00009ea2; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009ea2 (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

void shutdown_wait_key_pin_then_halt(void)

{
  ushort uVar1;
  undefined4 local_4;
  
  ref_setSR_PARAM(&local_4,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff74e,8,0);
  FUN_00002064(local_4);
  do {
    do {
      sh_busy_wait_count_times_8(5000);
      external_wdt_heartbeat_pulse();
      uVar1 = PFDR_W;
    } while ((uVar1 & 1) == 0);
    ref_whileLoop();
  } while( true );
}


