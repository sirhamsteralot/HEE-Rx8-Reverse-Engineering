/* ROM address: 0x0000f8d0; body bytes: 78; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000f8d4 (78 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000f8d0(void)

{
  undefined2 *puVar1;
  char *pcVar2;
  
  for (puVar1 = (undefined2 *)&DAT_ffffa4b4; puVar1 < &DAT_ffffa564; puVar1 = puVar1 + 0x2c) {
    for (pcVar2 = (char *)(puVar1 + 8); pcVar2 < puVar1 + 0x2c; pcVar2 = pcVar2 + 0x18) {
      injector_channel_disable((int)*pcVar2);
    }
  }
  DAT_ffffa564 = 0;
  DAT_ffffa568 = 0;
  DAT_ffffa56c = 0;
  return;
}


