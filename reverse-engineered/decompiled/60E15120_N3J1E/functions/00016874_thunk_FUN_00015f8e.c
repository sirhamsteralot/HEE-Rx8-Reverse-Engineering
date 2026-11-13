/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00015f8e [high]: 6-byte body: word 0xd321 = `mov.l @(0x168fc,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x168fc = 0x00015f8e (ROM-verified, big-endian) (ROM-verified at 0x00016874). Direct tail-jump to `FUN_00015f8e` 0x00015f8e; callers in callgraph: 0x0003e020. Upstream name `thunk_FUN_00015f8e` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00016874; body bytes: 6; decompiled */

void jump_to_FUN_00015f8e(void)

{
  FUN_00015f8e();
  return;
}


