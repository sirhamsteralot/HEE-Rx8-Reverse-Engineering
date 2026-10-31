/* ROM address: 0x0006500a; body bytes: 130; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000638fa (130 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006500a(ushort *param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  char cVar4;
  
  cVar2 = (&DAT_ffff8d54)[(uint)*param_1 * 2];
  bVar1 = *(byte *)(param_1 + 4);
  iVar3 = (int)(char)bVar1;
  if (*param_1 == 0) {
    cVar4 = '\0';
  }
  else {
    cVar4 = FUN_000678b4((int)(short)*param_1);
  }
  if ((((cVar2 != ' ') && (*(char *)(param_1 + 3) == -0x3f)) && (cVar4 == '\0')) &&
     ((DAT_ffff8e7e == '\x01' && (bVar1 < (byte)(&DAT_0007e4ce)[*param_1])))) {
    iVar3 = iVar3 + 1;
  }
  FUN_00062f2e(iVar3);
  *(char *)(param_2 + 8) = (char)iVar3;
  return;
}


