/* ROM address: 0x0002b6c2; body bytes: 64; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002be16 (64 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * ref_DSC_checkIfMode_x80(void)

{
  undefined1 *puVar1;
  
  if ((DAT_ffffbbf6 & 0x80) == 0x80) {
    puVar1 = (undefined1 *)(uint)engine_running_ffffa428;
    if (puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) {
      DAT_ffffbbcb = 1;
      return puVar1;
    }
  }
  else {
    puVar1 = &DAT_00078c6a;
  }
  DAT_ffffbbcb = 0;
  return puVar1;
}


