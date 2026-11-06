/* ROM address: 0x0005b5d4; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00059dc4 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_grablast28ByteFromE2(char param_1)

{
  undefined1 auStack_88 [132];
  
  e2ram_cached_byte_read(0x80,auStack_88,0xffffff80);
  ref_setupForUdsResponse_((int)param_1,auStack_88,0x80);
  return;
}


