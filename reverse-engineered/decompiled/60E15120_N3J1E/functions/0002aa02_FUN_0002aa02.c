/* ROM address: 0x0002aa02; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002b156 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002aa02(void)

{
  uint uVar1;
  char cVar2;
  undefined4 *puVar3;
  
  cVar2 = '\x03';
  uVar1 = 2;
  puVar3 = (undefined4 *)&DAT_ffffbb88;
  DAT_ffffbb6c = vehicle_speed_ffffbbb4;
  do {
    cVar2 = cVar2 + -1;
    puVar3 = puVar3 + -1;
    *puVar3 = (&DAT_ffffbb78)[uVar1 & 0xff];
    uVar1 = uVar1 + 0xff;
  } while (cVar2 != '\0');
  DAT_ffffbb78 = DAT_ffffbb6c;
  DAT_ffffbb68 = DAT_ffffbb7c;
  return;
}


