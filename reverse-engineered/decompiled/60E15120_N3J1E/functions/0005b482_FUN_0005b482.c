/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_tail_bulk_read [high]: e2ram_bulk_read_into_shadow(100, 0x9c): bulk-reads chip 0x64-0xff (ID string, 9-byte field, VIN, tire fields, tail) into the shadow 0xffffc28e.
 */
/* ROM address: 0x0005b482; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00059c72 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 e2ram_tail_bulk_read(void)

{
  undefined4 uVar1;
  
  uVar1 = e2ram_bulk_read_into_shadow(100,0x9c);
  return uVar1;
}


