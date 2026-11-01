/* ROM address: 0x0001c0ec; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001cb9c (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0001c0ec(void)

{
  undefined4 *puVar1;
  byte bVar2;
  
  bVar2 = 1;
  puVar1 = &DAT_ffffaecc;
  inferred_lambda_actual_ffffadec_ffffadec = 0x3f800000;
  DAT_ffffadf0 = 0x3f800000;
  DAT_ffffadf4 = 0x3f800000;
  do {
    bVar2 = bVar2 + 1;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (bVar2 < 0x15);
  return;
}


