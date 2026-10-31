/* ROM address: 0x00064f44; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063834 (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00064f44(ushort *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)*(char *)((int)param_1 + 7);
  if ((byte)(&DAT_0007e442)[*param_1] <= *(byte *)(param_2 + 9)) {
    iVar1 = 0;
  }
  FUN_00062e4a(iVar1);
  *(char *)(param_2 + 7) = (char)iVar1;
  return;
}


