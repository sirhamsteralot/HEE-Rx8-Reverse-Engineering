/* [ADDITIONAL SOURCE REVIEW]
 * recovery_finalize_set_pf3_halt [high]: Finalize path called from the 0xd204 recovery entry (pool 0xd2d0=0x9e68): jsr 0x4c80 (pool 0x9f20=0x4c80), jsr 0xd518 (pool 0x9f24=0xd518, RAM swap + SBL semaphore mark), bsr 0x9f0c r4=0; ref_setSR_PARAM 0xe0 (pool 0x9f18=0xe0, jsr pool 0x9f28=0x2054); PFDR_W 0xfffff74e bit 3 = 1 (pool 0x9f1a=0xf74e, r5=8 r6=1, jsr pool 0x9f2c=0x4bbc); jsr 0x2064 (pool 0x9f30), jsr 0x4cf0 (pool 0x9f34), jsr 0x3ad8 r4=0 (pool 0x9f38); halt at 0x9e9e.
 */
/* ROM address: 0x00009e68; body bytes: 58; decompiled_with_warnings */

/* Unique exact-byte match to related 60E0FC00 function at 00009e68 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

void recovery_finalize_set_pf3_halt(void)

{
  undefined4 local_4;
  
  FUN_00004c80();
  shutdown_ram_swap_semaphore_mark();
  FUN_00009f0c(0);
  ref_setSR_PARAM(&local_4,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff74e,8,1);
  FUN_00002064(local_4);
  FUN_00004cf0();
  FUN_00003ad8(0);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


