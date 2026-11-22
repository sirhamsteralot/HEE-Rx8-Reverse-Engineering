/* [ADDITIONAL SOURCE REVIEW]
 * cal_id_string_copy [high]: Renamed from inherited ref_ alias ref_ImmoRelatedFaultSomething_ (misnomer) on body evidence: the 72 B body copies the 16-byte calibration string 'N3J1E_1W.Z05' to 0xffffdf70..df7f and sets 0xffffdf90=0xc, returning 0x20 — called from boot task 0x1102a. Not an immobilizer fault handler.
 */
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


