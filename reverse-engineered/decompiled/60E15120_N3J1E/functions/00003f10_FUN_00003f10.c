/* ROM address: 0x00003f10; body bytes: 94; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003f10 (94 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00003f10(int param_1)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  
  psVar2 = (short *)(&PTR_DAT_00004af4)[*(char *)(param_1 + 1)];
  for (iVar3 = (int)*(short *)(&DAT_00004af8 + *(char *)(param_1 + 1) * 2); 0 < iVar3;
      iVar3 = iVar3 + -1) {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
    (&PTR_DAT_00004994)[sVar1 * 4][3] = (&PTR_DAT_00004994)[sVar1 * 4][3] + -1;
    os_mark_task_ready(param_1,(int)sVar1,(int)(char)(&DAT_00004992)[sVar1 * 0x10]);
  }
  return;
}


