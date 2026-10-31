/* ROM address: 0x0005965c; body bytes: 228; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00059678) */
/* WARNING: Removing unreachable block (ram,0x00059684) */
/* WARNING: Removing unreachable block (ram,0x0005968c) */
/* WARNING: Removing unreachable block (ram,0x000596a8) */
/* WARNING: Removing unreachable block (ram,0x000596b4) */
/* WARNING: Removing unreachable block (ram,0x000596bc) */
/* WARNING: Removing unreachable block (ram,0x000596d8) */
/* WARNING: Removing unreachable block (ram,0x000596e4) */
/* WARNING: Removing unreachable block (ram,0x000596ec) */
/* Unique exact-byte match to related 60E0FC00 function at 00057e14 (228 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_0005965c(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)0x1;
  if (((DAT_ffffd254 == '\x01') || (puVar1 = (undefined1 *)0x1, DAT_ffffd255 == '\x01')) ||
     (puVar1 = (undefined1 *)(uint)DAT_ffffd256, puVar1 == (undefined1 *)0x1)) {
    DAT_ffffd25c = 1;
  }
  if (DAT_ffffd27d != '\0') {
    puVar1 = &DAT_ffffd257;
    DAT_ffffd257 = 1;
    DAT_ffffd258 = 1;
    DAT_ffffd259 = 1;
  }
  DAT_ffffd27d = 0;
  return puVar1;
}


