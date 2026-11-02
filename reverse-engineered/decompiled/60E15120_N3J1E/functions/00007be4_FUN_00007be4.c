/* ROM address: 0x00007be4; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007be4 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_00007be4(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(uint)DAT_ffff9f96;
  if (puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) {
    puVar1 = &DAT_ffff9f97;
    DAT_ffff9fc6 = crank_sector_index_ffff9f95;
    if (0xb < DAT_ffff9f97) {
      DAT_ffff9fc6 = crank_sector_index_ffff9f95 + '$';
    }
  }
  else {
    DAT_ffff9fc6 = -1;
  }
  return puVar1;
}


