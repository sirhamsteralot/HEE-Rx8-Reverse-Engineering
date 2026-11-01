/* ROM address: 0x0003636c; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00036a8c (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_0003636c(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(uint)inferred_ram_c1d2_ffffc1d2_ffffc1d2;
  if (puVar1 != (undefined1 *)((int)&vector_usr_break + 3)) {
    inferred_ram_c1d2_ffffc1d2_ffffc1d2 = 0x33;
    DAT_ffffc275 = DAT_ffffc275 & 0xfd;
    DAT_ffffc247 = 0;
    DAT_ffffc234 = 0;
    puVar1 = &DAT_ffffc23c;
    DAT_ffffc23c = 0;
    DAT_ffffc23e = 1;
    DAT_ffffc238 = 0;
  }
  return puVar1;
}


