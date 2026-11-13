/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00054d90 [high]: 4-byte body: word 0xa034 = `bra 0x54d90` + delay-slot word 0x0009 (ROM-verified at 0x00054d24). Direct tail-jump to `FUN_00054d90` 0x00054d90; callers in callgraph: 0x00065980. Upstream name `thunk_FUN_00054d90` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00054d24; body bytes: 4; decompiled */

void jump_to_FUN_00054d90(void)

{
  FUN_00054d90();
  return;
}


