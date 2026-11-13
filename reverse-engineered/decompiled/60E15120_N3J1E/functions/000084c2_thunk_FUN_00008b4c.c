/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00008b4c [high]: 4-byte body: word 0xa343 = `bra 0x8b4c` + delay-slot word 0x0009 (ROM-verified at 0x000084c2). Direct tail-jump to `FUN_00008b4c` 0x00008b4c; callers in callgraph: 0x0000f960. Upstream name `thunk_FUN_00008b4c` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x000084c2; body bytes: 4; decompiled */

void jump_to_FUN_00008b4c(void)

{
  FUN_00008b4c();
  return;
}


