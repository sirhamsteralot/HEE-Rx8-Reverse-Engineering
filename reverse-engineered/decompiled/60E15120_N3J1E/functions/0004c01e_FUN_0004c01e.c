/* ROM address: 0x0004c01e; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004b1d6 (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * FUN_0004c01e(void)

{
  undefined4 *puVar1;
  
  puVar1 = &apv_command_percent_ffffbf84;
  if ((((DAT_ffffd1ad == '\0') && (DAT_ffffd1c5 == '\0')) &&
      (puVar1 = &DAT_0004c11c, apv_command_percent_ffffbf84 != 100.0)) &&
     (puVar1 = &DAT_0004c11c, apv_command_percent_ffffbf84 != 0.0)) {
    DAT_ffffce98 = 1;
  }
  else {
    DAT_ffffce98 = 0;
  }
  return puVar1;
}


