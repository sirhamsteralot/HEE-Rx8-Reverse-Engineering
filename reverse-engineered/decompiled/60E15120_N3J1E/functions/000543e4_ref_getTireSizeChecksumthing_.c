/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_tire_size_marker_check [high]: e2ram_cached_byte_read(0x95, local, 1); byte == '*' (0x2a) -> DAT_ffffd1b5 = 0 (default tire size), else DAT_ffffd1b5 = 1. Inherited ref_getTireSizeChecksumthing_ confirmed. Chip 0x95 = 0x2a in both dumps.
 */
/* ROM address: 0x000543e4; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000524c0 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

char e2ram_tire_size_marker_check(void)

{
  char cVar1;
  char local_8 [8];
  
  cVar1 = e2ram_cached_byte_read(0x95,local_8,1);
  if (cVar1 == '\0') {
    if (local_8[0] == '*') {
      DAT_ffffd1b5 = 0;
      cVar1 = '*';
    }
    else {
      cVar1 = '\x01';
      DAT_ffffd1b5 = 1;
    }
  }
  return cVar1;
}


