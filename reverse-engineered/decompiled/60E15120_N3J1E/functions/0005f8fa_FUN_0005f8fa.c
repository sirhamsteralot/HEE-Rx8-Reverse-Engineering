/* ROM address: 0x0005f8fa; body bytes: 86; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e206 (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_0005f8fa(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = FUN_00061800(0);
  if (((cVar1 == -0x40) || (cVar1 == -0x3f)) || (cVar1 == 'p')) {
    iVar2 = 1;
  }
  cVar1 = FUN_00061800(1);
  if (((cVar1 == -0x40) || (cVar1 == -0x3f)) || (cVar1 == 'p')) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


