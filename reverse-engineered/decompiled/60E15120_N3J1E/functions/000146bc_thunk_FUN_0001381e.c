/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_0001381e [high]: 6-byte body: word 0xd323 = `mov.l @(0x1474c,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x1474c = 0x0001381e (ROM-verified, big-endian) (ROM-verified at 0x000146bc). Direct tail-jump to `FUN_0001381e` 0x0001381e; callers in callgraph: 0x0003e020. Upstream name `thunk_FUN_0001381e` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x000146bc; body bytes: 6; decompiled */

void jump_to_FUN_0001381e(void)

{
  FUN_0001381e();
  return;
}


