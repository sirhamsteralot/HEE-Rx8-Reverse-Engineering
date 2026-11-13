/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_ecu_id_read [high]: Reads chip 0x64 (len 3) -> DAT_ffffd394 (+0x20), 0x68 (1) -> DAT_ffffd39a, 0x6a (2) -> DAT_ffffd398 (u16), 0x6c (1) -> DAT_ffffd39b via e2ram_cached_byte_read 0x37ef0. RX8 dump: 0x64-0x66='13H', 0x68='6', 0x6a-0x6b='02', 0x6c='0'.
 */
/* ROM address: 0x0005e664; body bytes: 206; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ce70 (206 bytes). Names prefixed ref_
   are inherited hypotheses. */

char e2ram_ecu_id_read(void)

{
  char cVar1;
  byte local_14;
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  
  cVar1 = e2ram_cached_byte_read(100,&local_14,3);
  if (cVar1 == '\0') {
    DAT_ffffd394 = ((uint)local_14 * 0x100 + (uint)bStack_13) * 0x10000 +
                   ((uint)bStack_12 * 0x100 + (uint)bStack_11 & (uint)&PTR_ref_LongFunc_0000ff00) +
                   0x20;
  }
  cVar1 = e2ram_cached_byte_read(0x68,&local_14,1);
  if (cVar1 == '\0') {
    DAT_ffffd39a = local_14;
  }
  cVar1 = e2ram_cached_byte_read(0x6a,&local_14,2);
  if (cVar1 == '\0') {
    DAT_ffffd398 = (ushort)local_14 * 0x100 + (ushort)bStack_13;
  }
  cVar1 = e2ram_cached_byte_read(0x6c,&local_14,1);
  if (cVar1 == '\0') {
    DAT_ffffd39b = local_14;
  }
  return cVar1;
}


