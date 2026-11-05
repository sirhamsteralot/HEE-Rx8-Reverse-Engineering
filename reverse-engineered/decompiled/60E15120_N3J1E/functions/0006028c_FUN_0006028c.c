/* ROM address: 0x0006028c; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005eb7c (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006028c(void)

{
  undefined1 *puVar1;
  ushort uVar2;
  
  puVar1 = &dtc_state_array_ffffd5fc;
  uVar2 = 0;
  do {
    *puVar1 = 0;
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x8c);
  return;
}


