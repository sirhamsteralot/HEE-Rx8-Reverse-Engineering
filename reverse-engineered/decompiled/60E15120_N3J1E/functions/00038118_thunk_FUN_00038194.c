/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00038194 [high]: 4-byte body: word 0xa03c = `bra 0x38194` + delay-slot word 0x0009 (ROM-verified at 0x00038118). Direct tail-jump to `FUN_00038194` 0x00038194; callers in callgraph: 0x0002a1a0. Upstream name `thunk_FUN_00038194` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00038118; body bytes: 4; decompiled */

void jump_to_FUN_00038194(void)

{
  FUN_00038194();
  return;
}


