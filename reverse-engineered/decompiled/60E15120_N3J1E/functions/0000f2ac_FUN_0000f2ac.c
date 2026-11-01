/* ROM address: 0x0000f2ac; body bytes: 112; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000f2b0 (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_0000f2ac(void)

{
  char cVar1;
  char *pcVar2;
  
  cVar1 = FUN_00010230();
  DAT_ffffa4b3 = DAT_ffff9f94;
  if (cVar1 == '\x01') {
    if (4 < DAT_ffff9f94) {
      if (DAT_ffff9f94 < 0xb) {
        DAT_ffffa4b0 = 0;
        DAT_ffffa4b1 = 0;
        DAT_ffffa4b3 = DAT_ffff9f94;
        return &DAT_00079061;
      }
      DAT_ffffa4b0 = 0;
      DAT_ffffa4b1 = 0;
      DAT_ffffa4b3 = DAT_ffff9f94;
      return &DAT_00079061;
    }
    pcVar2 = "\x01";
  }
  else {
    if ((undefined1 *)(uint)inferred_ram_ce32_ffffce32_ffffce32 != (undefined1 *)((int)&vector_Poweron_Reset + 1U)) {
      DAT_ffffa4b0 = 0;
      DAT_ffffa4b1 = 0;
      DAT_ffffa4b3 = DAT_ffff9f94;
      return (undefined1 *)(uint)inferred_ram_ce32_ffffce32_ffffce32;
    }
    pcVar2 = "";
  }
  DAT_ffffa4b1 = *pcVar2;
  DAT_ffffa4b0 = DAT_ffffa4b1;
  return (undefined1 *)(int)DAT_ffffa4b1;
}


