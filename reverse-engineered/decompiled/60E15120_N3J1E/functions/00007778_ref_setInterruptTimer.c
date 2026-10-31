/* ROM address: 0x00007778; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007778 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

void atu_ch10b_tick_enable(void)

{
  ushort uVar1;
  
  if (DAT_ffff9fc4 == '\0') {
    ATUII_TSR10_W = 0xb;
    FUN_00007b58();
    uVar1 = ATUII_TIER10_W;
    ATUII_TIER10_W = uVar1 & 0xfffb | 4;
    DAT_ffff9fc4 = '\x01';
  }
  return;
}


