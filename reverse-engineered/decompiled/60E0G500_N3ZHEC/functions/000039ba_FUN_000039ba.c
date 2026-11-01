/* ROM address: 0x000039ba; body bytes: 110; decompiled */

undefined4 FUN_000039ba(char *param_1,undefined2 param_2,uint param_3)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  
  psVar2 = (short *)(param_3 * 8 + *(int *)(param_1 + 0x20));
  psVar3 = *(short **)(psVar2 + 2);
  if (*psVar3 == -1) {
    psVar3[1] = *psVar2;
    *psVar3 = *psVar2;
    (&DAT_ffff7668)[(int)param_3 >> 3] =
         (&DAT_ffff7668)[(int)param_3 >> 3] | (&DAT_00003d48)[param_3 & 7];
    *(undefined2 *)(*(int *)(param_1 + 0x24) + psVar3[1] * 2) = param_2;
    if ((int)*param_1 < (int)param_3) {
      *param_1 = (char)param_3;
      *(undefined2 *)(param_1 + 6) = param_2;
      return 1;
    }
  }
  else {
    if (psVar3[1] == psVar2[1]) {
      sVar1 = *psVar2;
    }
    else {
      sVar1 = psVar3[1] + 1;
    }
    psVar3[1] = sVar1;
    *(undefined2 *)(*(int *)(param_1 + 0x24) + psVar3[1] * 2) = param_2;
  }
  return 0;
}


