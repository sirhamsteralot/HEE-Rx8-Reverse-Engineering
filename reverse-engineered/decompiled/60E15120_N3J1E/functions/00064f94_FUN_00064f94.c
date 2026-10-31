/* ROM address: 0x00064f94; body bytes: 118; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063884 (118 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00064f94(ushort *param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  char cVar4;
  
  cVar2 = (&DAT_ffff8d54)[(uint)*param_1 * 2];
  bVar1 = *(byte *)((int)param_1 + 9);
  iVar3 = (int)(char)bVar1;
  if (*param_1 == 0) {
    cVar4 = '\0';
  }
  else {
    cVar4 = FUN_000678b4((int)(short)*param_1);
  }
  if ((((cVar2 == '\x11') && (*(char *)(param_1 + 3) == -0x40)) && (cVar4 == '\0')) &&
     (bVar1 < (byte)(&DAT_0007e442)[*param_1])) {
    iVar3 = iVar3 + 1;
  }
  FUN_00062ebc(iVar3);
  *(char *)(param_2 + 9) = (char)iVar3;
  return;
}


