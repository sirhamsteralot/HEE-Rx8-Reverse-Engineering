/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_000601b2 [high]: 4-byte body: word 0xa20e = `bra 0x601b2` + delay-slot word 0x0009 (ROM-verified at 0x0005fd92). Direct tail-jump to `FUN_000601b2` 0x000601b2; callers in callgraph: 0x00059852. Upstream name `thunk_FUN_000601b2` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x0005fd92; body bytes: 4; decompiled */

void jump_to_FUN_000601b2(void)

{
  FUN_000601b2();
  return;
}


