/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00054b62 [high]: 6-byte body: word 0xd309 = `mov.l @(0x68da4,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x68da4 = 0x00054b62 (ROM-verified, big-endian) (ROM-verified at 0x00068d7c). Direct tail-jump to `FUN_00054b62` 0x00054b62; callers in callgraph: 0x0006859e. Upstream name `thunk_FUN_00054b62` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00068d7c; body bytes: 6; decompiled */

void jump_to_FUN_00054b62(void)

{
  FUN_00054b62();
  return;
}


