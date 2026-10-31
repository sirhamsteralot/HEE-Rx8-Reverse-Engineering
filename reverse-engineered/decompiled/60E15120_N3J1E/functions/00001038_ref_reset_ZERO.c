/* ROM address: 0x00001038; body bytes: 66; decompiled_with_warnings */

/* Unique exact-byte match to related 60E0FC00 function at 00001038 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_reset_ZERO(int param_1)

{
  code *pcVar1;
  
  ref_resetWatchdog_00001364();
  ref_resetOBDCAN_();
  ref_handleException_(param_1);
  if (param_1 == 0) {
    pcVar1 = (code *)&LAB_0000d204;
  }
  else {
    FUN_000012a2();
    pcVar1 = FUN_00001378;
  }
  FUN_00001090(pcVar1);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


