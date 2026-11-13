/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_upper_half_uds_dump [high]: e2ram_cached_byte_read(0x80, buf, 0x80) then ref_setupForUdsResponse_(svc, buf, 0x80): returns EEPROM bytes 0x80-0xff (128 B, VIN at 0x80-0x90) as a UDS response. Inherited ref_grablast28ByteFromE2 name was wrong about the length/offset.
 */
/* ROM address: 0x0005b5d4; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00059dc4 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

void e2ram_upper_half_uds_dump(char param_1)

{
  undefined1 auStack_88 [132];
  
  e2ram_cached_byte_read(0x80,auStack_88,0xffffff80);
  ref_setupForUdsResponse_((int)param_1,auStack_88,0x80);
  return;
}


