/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00054a36 [high]: 6-byte body: word 0xd30a = `mov.l @(0x68d9c,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x68d9c = 0x00054a36 (ROM-verified, big-endian) (ROM-verified at 0x00068d70). Direct tail-jump to `FUN_00054a36` 0x00054a36; callers in callgraph: 0x0006892a, 0x00068996. Upstream name `thunk_FUN_00054a36` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00068d70; body bytes: 6; decompiled */

void jump_to_FUN_00054a36(void)

{
  FUN_00054a36();
  return;
}


