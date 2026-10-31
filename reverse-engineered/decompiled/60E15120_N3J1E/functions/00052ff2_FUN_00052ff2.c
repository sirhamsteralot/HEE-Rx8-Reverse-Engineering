/* ROM address: 0x00052ff2; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00050f76 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_00052ff2(void)

{
  undefined1 *puVar1;
  
  puVar1 = &DAT_0007dc26;
  if ((1 < DAT_ffffd145) &&
     (puVar1 = (undefined1 *)-((((int)DAT_ffffcfb5 & 0x80U) == 0) - 1),
     puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) {
    DAT_ffffd147 = 1;
  }
  return puVar1;
}


