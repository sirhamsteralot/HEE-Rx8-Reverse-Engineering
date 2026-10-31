/* ROM address: 0x00010c90; body bytes: 142; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00010cb4 (142 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00010c90(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  float fVar3;
  
  fVar3 = 65536.0;
  for (pcVar2 = (char *)(param_1 + 0xc); pcVar2 < (char *)(param_1 + 0x2c); pcVar2 = pcVar2 + 0x10)
  {
    if ((pcVar2[4] == '\0') && (pcVar2[3] == '\0')) {
      *(int *)(pcVar2 + 8) = *(int *)(pcVar2 + 0xc);
      iVar1 = *(int *)(pcVar2 + 0xc) - param_2;
      if (0 < iVar1) {
        iVar1 = 0;
      }
      iVar1 = FUN_000107d4(iVar1);
      ref_initSparkOutput((float)iVar1 / fVar3,(int)*pcVar2);
      pcVar2[3] = '\x01';
    }
  }
  *(undefined1 *)(param_1 + 1) = 1;
  *(undefined1 *)(param_1 + 2) = 0;
  return;
}


