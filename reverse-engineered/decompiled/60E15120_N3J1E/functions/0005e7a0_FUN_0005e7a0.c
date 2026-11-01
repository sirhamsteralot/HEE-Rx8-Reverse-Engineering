/* ROM address: 0x0005e7a0; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005cfac (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0005e7a0(void)

{
  char cVar1;
  undefined2 local_c;
  
  cVar1 = FUN_00037ef0(0x78,&local_c,2);
  if (cVar1 == '\0') {
    cVar1 = (char)local_c;
  }
  else {
    local_c = 0xffff;
  }
  inferred_ram_d3a0_ffffd3a0_ffffd3a0 = local_c;
  DAT_ffffd3a8 = local_c;
  DAT_ffffd3af = 0;
  DAT_ffffd3ae = 0;
  return cVar1;
}


