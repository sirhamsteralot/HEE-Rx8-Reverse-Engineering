/* [ADDITIONAL SOURCE REVIEW]
 * os_mark_task_ready [high]: Appends task id to ready ring at ctrl+0x24 (0xffff74a0)[tail], sets class bitmap 0xffff7668 (bit tbl 0x3d48[class&7] in byte class>>3), and if class > ctrl[0] (cmp/hi, unsigned) sets ctrl[0]=class, ctrl+6=task (disasm 0x39f6-0x3a00). Dynamic: bitmap 0x11000000 -> 0x15000000 on post to slot 2 (class 2).
 * RAM 0xffff7668 os_ready_bitmap (uint32): 0x39ba sets bit tbl 0x3d48[class&7] in byte (class>>3); after boot 0x11000000 (classes 0 and 4 = init tasks {0,17}); after post to queue slot 2 observed 0x15000000 (class 2 added).
 * RAM 0xffff74a0 os_ready_ring (uint16[]): ctrl+0x24 (0xffff765c) points here; 0x39ba appends the task id at ring[tail] when marking ready.
 */
/* ROM address: 0x000039ba; body bytes: 110; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000039ba (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 os_mark_task_ready(char *param_1,undefined2 param_2,uint param_3)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  
  psVar2 = (short *)(param_3 * 8 + *(int *)(param_1 + 0x20));
  psVar3 = *(short **)(psVar2 + 2);
  if (*psVar3 == -1) {
    psVar3[1] = *psVar2;
    *psVar3 = *psVar2;
    (&os_ready_bitmap_ffff7668)[(int)param_3 >> 3] =
         (&os_ready_bitmap_ffff7668)[(int)param_3 >> 3] | (&tbl_os_class_bit_00003d48)[param_3 & 7];
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


