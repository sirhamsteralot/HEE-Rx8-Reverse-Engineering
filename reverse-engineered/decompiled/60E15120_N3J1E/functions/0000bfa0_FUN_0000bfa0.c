/* [ADDITIONAL SOURCE REVIEW]
 * sci4_send_bytes [high]: SCI4 byte transmit: SCI_SCR4_B 0xfffff022 |= 0x20 (TE), loop over len bytes: wait SCI_SSR4_B 0xfffff024 bit 0x80 (TDRE), write SCI_TDR4_B 0xfffff023, clear TDRE (SSR4 = b & 0x7f | 0x78); end wait bit 0x4 (TEND), SCR4 &= 0xb. Register names from symbols.tsv.
 */
/* ROM address: 0x0000bfa0; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000bfa0 (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

void sci4_send_bytes(undefined4 param_1,uint param_2)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_10;
  
  puVar4 = &local_10;
  bVar2 = SCI_SCR4_B;
  SCI_SCR4_B = bVar2 & 0xb | 0x20;
  local_10 = param_1;
  for (iVar3 = 0; iVar3 < (int)(param_2 & 0xff); iVar3 = iVar3 + 1) {
    do {
      bVar2 = SCI_SSR4_B;
    } while ((bVar2 & 0x80) == 0);
    uVar1 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    SCI_TDR4_B = uVar1;
    bVar2 = SCI_SSR4_B;
    SCI_SSR4_B = bVar2 & 0x7f | 0x78;
  }
  do {
    bVar2 = SCI_SSR4_B;
  } while ((bVar2 & 4) == 0);
  bVar2 = SCI_SCR4_B;
  SCI_SCR4_B = bVar2 & 0xb;
  return;
}


