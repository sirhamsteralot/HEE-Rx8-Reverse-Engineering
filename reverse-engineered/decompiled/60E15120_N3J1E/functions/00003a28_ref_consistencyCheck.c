/* ROM address: 0x00003a28; body bytes: 124; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003a28 (124 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_consistencyCheck(char *param_1,char param_2)

{
  short *psVar1;
  short *psVar2;
  uint uVar3;
  
  psVar2 = (short *)(param_2 * 8 + *(int *)(param_1 + 0x20));
  psVar1 = *(short **)(psVar2 + 2);
  uVar3 = (uint)param_2;
  if (*psVar1 == psVar1[1]) {
    *psVar1 = -1;
    (&os_ready_bitmap_ffff7668)[(int)uVar3 >> 3] = (&os_ready_bitmap_ffff7668)[(int)uVar3 >> 3] & (&DAT_00003d50)[uVar3 & 7]
    ;
    if (uVar3 != (int)*param_1) {
      return 0;
    }
    FUN_00003c80();
  }
  else {
    if (*psVar1 == psVar2[1]) {
      *psVar1 = *psVar2;
    }
    else {
      *psVar1 = *psVar1 + 1;
    }
    if (uVar3 != (int)*param_1) {
      return 0;
    }
    *(undefined2 *)(param_1 + 6) = *(undefined2 *)(&os_ready_ring_ffff74a0 + *psVar1 * 2);
  }
  return 1;
}


