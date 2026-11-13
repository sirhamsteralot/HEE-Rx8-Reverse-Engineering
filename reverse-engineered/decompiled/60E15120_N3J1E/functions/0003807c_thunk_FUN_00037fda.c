/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00037fda [high]: 6-byte body: word 0xd30d = `mov.l @(0x380b4,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x380b4 = 0x00037fda (ROM-verified, big-endian) (ROM-verified at 0x0003807c). Direct tail-jump to `FUN_00037fda` 0x00037fda; callers in callgraph: 0x0001102a. Upstream name `thunk_FUN_00037fda` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x0003807c; body bytes: 6; decompiled */

void jump_to_FUN_00037fda(void)

{
  FUN_00037fda();
  return;
}


