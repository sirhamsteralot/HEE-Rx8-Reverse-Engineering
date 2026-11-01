/* ROM address: 0x0005fc18; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e524 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_checkIfDeviceControl_(void)

{
  diag_permission_mask_ffffd3b4_ffffd3b4 = 0x40;
  if (DAT_ffffd1ce == '\x01') {
    diag_permission_mask_ffffd3b4_ffffd3b4 = 0xfffd;
  }
  return DAT_ffffd1ce;
}


