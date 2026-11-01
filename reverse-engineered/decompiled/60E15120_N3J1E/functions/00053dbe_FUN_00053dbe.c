/* ROM address: 0x00053dbe; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00051ed2 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_00053dbe(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if ((DAT_ffffd1a3 == '\x01') || (cVar1 = DAT_ffffd1a4, DAT_ffffd1a4 == '\x01')) {
    inferred_ram_d1a1_ffffd1a1_ffffd1a1 = 1;
  }
  else {
    inferred_ram_d1a1_ffffd1a1_ffffd1a1 = 0;
  }
  return cVar1;
}


