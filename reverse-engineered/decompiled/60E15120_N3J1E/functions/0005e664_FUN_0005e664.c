/* ROM address: 0x0005e664; body bytes: 206; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ce70 (206 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0005e664(void)

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


