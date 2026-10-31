/* ROM address: 0x000436f8; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00042f2c (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * ref_getThrottleLessThanLookupTimer(void)

{
  undefined1 *puVar1;
  
  if (DAT_ffffca46 == '\0') {
    puVar1 = (undefined1 *)0x0;
    DAT_ffffca41 = 0;
  }
  else {
    puVar1 = &DAT_0007b612;
    if (DAT_ffffca41 < 4) {
      DAT_ffffca41 = DAT_ffffca41 + 1;
    }
  }
  return puVar1;
}


