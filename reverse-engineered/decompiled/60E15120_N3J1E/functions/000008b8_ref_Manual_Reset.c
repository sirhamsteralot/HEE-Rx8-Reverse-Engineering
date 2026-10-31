/* ROM address: 0x000008b8; body bytes: 20; decompiled_with_warnings */

/* Unique exact-byte match to related 60E0FC00 function at 000008b8 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_Manual_Reset(void)

{
  boot_wait_nmi_pin_high();
  FUN_000008f6();
  ref_resetHandler_(0);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


