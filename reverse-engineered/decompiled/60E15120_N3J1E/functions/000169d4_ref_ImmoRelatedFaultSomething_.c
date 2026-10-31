/* ROM address: 0x000169d4; body bytes: 72; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000169e4) */
/* Unique exact-byte match to related 60E0FC00 function at 000167d8 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_ImmoRelatedFaultSomething_(void)

{
  byte bVar1;
  byte bVar2;
  
  DAT_ffffdfa0._0_1_ = 0;
  bVar1 = 0;
  do {
    bVar2 = bVar1 + 1;
    (&DAT_ffffdf70)[bVar1] = "N3J1E_1W.Z05"[bVar1];
    bVar1 = bVar2;
  } while (bVar2 < 0x10);
  DAT_ffffdf90 = 0xc;
  return 0x20;
}


