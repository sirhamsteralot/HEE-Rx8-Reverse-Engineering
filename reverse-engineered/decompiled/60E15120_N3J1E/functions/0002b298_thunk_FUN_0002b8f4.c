/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_0002b8f4 [high]: 4-byte body: word 0xa32c = `bra 0x2b8f4` + delay-slot word 0x0009 (ROM-verified at 0x0002b298). Direct tail-jump to `FUN_0002b8f4` 0x0002b8f4; callers in callgraph: 0x0002a1a0. Upstream name `thunk_FUN_0002b8f4` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x0002b298; body bytes: 4; decompiled */

void jump_to_FUN_0002b8f4(void)

{
  FUN_0002b8f4();
  return;
}


