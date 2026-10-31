/* ROM address: 0x000559dc; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00053cf8 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_000559dc(void)

{
  undefined1 *puVar1;
  
  puVar1 = &DAT_0007dee4;
  if (DAT_ffffd1c8 != '\0') {
    FUN_00055992(0xff);
    puVar1 = (undefined1 *)FUN_00061b02(&PTR_ref_LongFunc_0000ff00);
  }
  DAT_ffffd1c8 = 0;
  return puVar1;
}


