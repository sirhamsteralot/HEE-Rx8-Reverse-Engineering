/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00029134 [high]: 4-byte body: word 0xa060 = `bra 0x29134` + delay-slot word 0x0009 (ROM-verified at 0x00029070). Direct tail-jump to `FUN_00029134` 0x00029134; callers in callgraph: 0x0002a1a0. Upstream name `thunk_FUN_00029134` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00029070; body bytes: 4; decompiled */

void jump_to_FUN_00029134(void)

{
  FUN_00029134();
  return;
}


