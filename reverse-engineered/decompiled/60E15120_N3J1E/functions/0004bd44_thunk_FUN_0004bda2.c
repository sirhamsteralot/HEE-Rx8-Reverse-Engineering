/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_0004bda2 [high]: 4-byte body: word 0xa02d = `bra 0x4bda2` + delay-slot word 0x0009 (ROM-verified at 0x0004bd44). Direct tail-jump to `FUN_0004bda2` 0x0004bda2; callers in callgraph: 0x0002a1a0. Upstream name `thunk_FUN_0004bda2` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x0004bd44; body bytes: 4; decompiled */

void jump_to_FUN_0004bda2(void)

{
  FUN_0004bda2();
  return;
}


