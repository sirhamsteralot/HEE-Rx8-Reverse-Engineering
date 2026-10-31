/* ROM address: 0x0001c112; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001cbc2 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_0001c112(void)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 1;
  iVar1 = 4;
  do {
    bVar2 = bVar2 + 1;
    *(undefined4 *)((int)&DAT_ffffaf48 + iVar1) = 0;
    *(undefined4 *)((int)&DAT_ffffaf9c + iVar1) = 0;
    iVar1 = iVar1 + 4;
  } while (bVar2 < 0x15);
  return iVar1;
}


