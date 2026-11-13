/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_0003ec3c [high]: 6-byte body: word 0xd32d = `mov.l @(0x19ef4,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x19ef4 = 0x0003ec3c (ROM-verified, big-endian) (ROM-verified at 0x00019e3c). Direct tail-jump to `FUN_0003ec3c` 0x0003ec3c; callers in callgraph: 0x000113b8. Upstream name `thunk_FUN_0003ec3c` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00019e3c; body bytes: 6; decompiled */

void jump_to_FUN_0003ec3c(void)

{
  FUN_0003ec3c();
  return;
}


