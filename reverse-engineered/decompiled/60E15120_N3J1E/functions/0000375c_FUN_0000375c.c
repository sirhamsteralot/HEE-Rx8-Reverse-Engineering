/* [EXPORT CLEANUP]
 * Computed indirect jump at 0x37ac: slot = incoming r2 + ROM32[0x37c0] (=0x4b34)
 * - zero-extended byte at [r13]; target = ROM32[slot]. The sibling path at
 * 0x3794-0x379a tail-jumps to ROM32[0x37bc] (=0x3848). Index bounds, record
 * layout and pointer-table extent are not established; this stays a computed
 * dispatch, not a recovered switch.
 */
/* ROM address: 0x0000375c; body bytes: 96; decompiled_with_warnings */

int FUN_0000375c(int param_1,short param_2)

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
  iVar4 = (**(code **)((int)&PTR_LAB_00004b34 +
                      ((int)*pcVar5 - (uint)(byte)(&DAT_00004990)[iVar4 * 0x10])))
                    (*(undefined4 *)(param_1 + 0xc));
  return iVar4;
}


