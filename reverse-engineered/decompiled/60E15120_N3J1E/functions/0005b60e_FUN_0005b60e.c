/* ROM address: 0x0005b60e; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00059dfe (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0005b60e(char param_1)

{
  undefined1 auStack_c [8];
  
  e2ram_cached_byte_read(100,auStack_c,3);
  ref_setupForUdsResponse_((int)param_1,auStack_c,3);
  return;
}


