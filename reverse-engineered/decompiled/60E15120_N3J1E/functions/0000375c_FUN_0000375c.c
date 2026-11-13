/* [ADDITIONAL SOURCE REVIEW]
 * os_switch_to_task [high]: Sets ctrl+4 = task index, ctrl+0x18 = task record (0x4990 + idx*0x10), ctrl+0x14 = stack ptr from PTR_DAT_00004994[idx], then computed jump via PTR_FUN_00004998[idx] (task table 0x4998). Emulator: vec-0x378 handler reaches it via 0x9630.
 * RAM 0xffff7638 os_ctrl_block (uint8[0x20]): OS ctrl block base; mov.l pool 0x3278/0x32ec/0x3388 in 0x3238, pool 0x3e00 in 0x3db0, pool 0x3e80 in 0x3e10 (os_init) among 11 pool refs; members +4/+6/+8/+0x14/+0x18 are the count/flags/ptr cells; os_switch_to_task 0x375c writes ctrl+4, ctrl+0x14, ctrl+0x18.
 */
/* [EXPORT CLEANUP]
 * Computed indirect jump at 0x37ac: slot = incoming r2 + ROM32[0x37c0] (=0x4b34)
 * - zero-extended byte at [r13]; target = ROM32[slot]. The sibling path at
 * 0x3794-0x379a tail-jumps to ROM32[0x37bc] (=0x3848). Index bounds, record
 * layout and pointer-table extent are not established; this stays a computed
 * dispatch, not a recovered switch.
 */
/* ROM address: 0x0000375c; body bytes: 96; decompiled_with_warnings */

int os_switch_to_task(int param_1,short param_2)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  char *pcVar5;
  
  iVar4 = (int)param_2;
  pcVar5 = (&PTR_DAT_00004994)[iVar4 * 4];
  *(short *)(param_1 + 4) = param_2;
  *(undefined **)(param_1 + 0x18) = &DAT_00004990 + iVar4 * 0x10;
  *(char **)(param_1 + 0x14) = pcVar5;
  FUN_000035cc();
  *(undefined4 *)(param_1 + 8) = 0;
  if (*pcVar5 == 0) {
    cVar1 = (&DAT_00004992)[iVar4 * 0x10];
    pcVar5[1] = cVar1;
    iVar2 = *(int *)(param_1 + 0xc);
    *(int *)(pcVar5 + 4) = iVar2;
    puVar3 = (&PTR_FUN_00004998)[iVar4 * 4];
    *(undefined4 *)(iVar2 + -4) = 0;
    *(undefined **)(iVar2 + -8) = puVar3;
    return (int)cVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x000037ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar4 = (**(code **)((int)&tbl_os_resume_jumptable_00004b34 +
                      ((int)*pcVar5 - (uint)(byte)(&DAT_00004990)[iVar4 * 0x10])))
                    (*(undefined4 *)(param_1 + 0xc));
  return iVar4;
}


