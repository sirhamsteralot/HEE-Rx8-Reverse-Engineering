/* ROM address: 0x0005402e; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00052146 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_0005402e(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(uint)engine_injectors_off_ffffa42c;
  if ((puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) || (DAT_ffffd1ae == '\0')) {
    puVar1 = &DAT_0007dea8;
    DAT_ffffd1ac = '\b';
  }
  else if (DAT_ffffd1ac != '\0') {
    DAT_ffffd1ac = DAT_ffffd1ac + -1;
  }
  return puVar1;
}


