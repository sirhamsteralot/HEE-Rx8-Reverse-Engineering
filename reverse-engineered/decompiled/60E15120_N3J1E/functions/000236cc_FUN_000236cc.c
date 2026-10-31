/* ROM address: 0x000236cc; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00023f40 (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000236cc(void)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  byte bVar4;
  
  FUN_0002377a();
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  DAT_ffffb476 = 0;
  bVar4 = 0;
  DAT_ffffb440 = 0xa55a;
  iVar3 = 0;
  do {
    bVar4 = bVar4 + 1;
    DAT_ffffb476 = DAT_ffffb476 + *(short *)((int)&DAT_ffffb440 + iVar3);
    iVar3 = iVar3 + 2;
  } while (bVar4 < 0x1b);
  cVar2 = FUN_0000b886(&DAT_ffffb440,0x1c);
  if (cVar2 != '\0') {
    DAT_ffffb43b = 1;
  }
  ref_setSR(uVar1);
  return;
}


