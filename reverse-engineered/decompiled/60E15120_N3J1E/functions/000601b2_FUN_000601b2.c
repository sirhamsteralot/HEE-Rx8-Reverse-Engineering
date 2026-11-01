/* ROM address: 0x000601b2; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005eaa2 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000601b2(void)

{
  undefined1 *puVar1;
  ushort uVar2;
  
  uVar2 = 0;
  puVar1 = &dtc_ram_flag_table_ffffd570_ffffd570;
  do {
    uVar2 = uVar2 + 1;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x8c);
  DAT_ffffd3c0 = 0;
  return;
}


