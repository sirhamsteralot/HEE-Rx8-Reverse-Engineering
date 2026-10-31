/* ROM address: 0x000363d0; body bytes: 78; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00036af0 (78 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_000363d0(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(uint)DAT_ffffc239;
  if (puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) {
    if (DAT_ffffc237 != 0xff) {
      DAT_ffffc237 = DAT_ffffc237 + 1;
    }
    if (0x18 < DAT_ffffc237) {
      if (DAT_ffffc279 == '\0') {
        DAT_ffffc239 = 0;
      }
      else {
        puVar1 = &DAT_ffffc240;
        DAT_ffffc279 = DAT_ffffc279 + -1;
        DAT_ffffc240 = 1;
      }
      DAT_ffffc237 = 0;
    }
  }
  return puVar1;
}


