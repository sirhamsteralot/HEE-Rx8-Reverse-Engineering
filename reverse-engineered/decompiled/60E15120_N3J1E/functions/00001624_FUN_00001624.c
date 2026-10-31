/* ROM address: 0x00001624; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001624 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001624(void)

{
  undefined1 *puVar1;
  byte bVar2;
  undefined1 local_10;
  undefined1 local_f [11];
  
  bVar2 = 1;
  puVar1 = &local_10;
  local_10 = 0x30;
  do {
    puVar1 = puVar1 + 1;
    bVar2 = bVar2 + 1;
    *puVar1 = 0;
  } while (bVar2 < 8);
  FUN_00001150(&local_10);
  return;
}


