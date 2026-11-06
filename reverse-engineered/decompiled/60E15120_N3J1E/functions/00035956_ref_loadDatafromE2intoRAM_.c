/* ROM address: 0x00035956; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00036076 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_loadDatafromE2intoRAM_(void)

{
  undefined4 uVar1;
  
  uVar1 = e2ram_bulk_read_into_shadow(0,0x20);
  return uVar1;
}


