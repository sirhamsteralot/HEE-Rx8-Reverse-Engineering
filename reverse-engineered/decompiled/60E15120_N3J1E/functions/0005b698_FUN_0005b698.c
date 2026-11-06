/* ROM address: 0x0005b698; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00059e88 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0005b698(char param_1)

{
  undefined1 auStack_c [8];
  
  e2ram_cached_byte_read(0x6a,auStack_c,2);
  ref_setupForUdsResponse_((int)param_1,auStack_c,2);
  return;
}


