/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_field_6e_uds_dump [high]: e2ram_cached_byte_read(0x6e, buf, 9); ref_setupForUdsResponse_(svc, buf, 9). Chip 0x6e-0x76 is erased (0xff) in both upstream dumps.
 */
/* ROM address: 0x0005b704; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00059ef4 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

void e2ram_field_6e_uds_dump(char param_1)

{
  undefined1 auStack_14 [16];
  
  e2ram_cached_byte_read(0x6e,auStack_14,9);
  ref_setupForUdsResponse_((int)param_1,auStack_14,9);
  return;
}


