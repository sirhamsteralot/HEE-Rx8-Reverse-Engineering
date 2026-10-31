/* ROM address: 0x000368aa; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00036fca (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000368aa(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = ATUII_TCNT0H_W;
  DAT_ffffc277 = (undefined1)((uVar1 & (uint)&PTR_ref_LongFunc_0000ff00) >> 8);
  if ((uVar1 & (uint)&PTR_ref_LongFunc_0000ff00) == 0) {
    DAT_ffffc277 = 0x5a;
  }
  DAT_ffffc244 = 1;
  uVar2 = FUN_00035438((int)DAT_ffffc27a);
  DAT_ffffc27f = (char)((uint)uVar2 >> 0x10);
  DAT_ffffc280 = (char)((uint)uVar2 >> 8);
  DAT_ffffc281 = (char)uVar2;
  return;
}


