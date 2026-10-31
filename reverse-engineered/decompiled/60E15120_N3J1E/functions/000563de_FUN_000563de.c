/* ROM address: 0x000563de; body bytes: 74; decompiled_with_warnings */

/* Unique exact-byte match to related 60E0FC00 function at 000546fa (74 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_000563de(char param_1)

{
  char cVar1;
  
  cVar1 = DAT_ffffd1dc;
  if (param_1 == '\x03') {
    DAT_ffffd1dc = 3;
  }
  else if (param_1 == '\x01') {
    if (DAT_ffffd1dc == '\x03') {
      FUN_000564d4();
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    DAT_ffffd1dc = 0;
    param_1 = cVar1;
  }
  else {
    DAT_ffffd1dc = 0;
  }
  return param_1;
}


