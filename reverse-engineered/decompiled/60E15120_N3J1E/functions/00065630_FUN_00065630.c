/* ROM address: 0x00065630; body bytes: 40; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00063f20 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00065630(void)

{
  undefined4 uVar1;
  float fVar2;
  float extraout_fr0;
  
  fVar2 = (float)FUN_0005fc72();
  uVar1 = FUN_0005fc6c();
  if (extraout_fr0 <= fVar2) {
    uVar1 = rx8_pack_u8_with_complement(1);
    _DAT_ffff8e7c = (undefined2)uVar1;
  }
  return uVar1;
}


