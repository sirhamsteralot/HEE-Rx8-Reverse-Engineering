/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_0002529e [high]: 6-byte body: word 0xd318 = `mov.l @(0x25414,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x25414 = 0x0002529e (ROM-verified, big-endian) (ROM-verified at 0x000253b2). Direct tail-jump to `FUN_0002529e` 0x0002529e; callers in callgraph: 0x000113b8, 0x0003de70. Upstream name `thunk_FUN_0002529e` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x000253b2; body bytes: 6; decompiled */

void jump_to_FUN_0002529e(void)

{
  FUN_0002529e();
  return;
}


