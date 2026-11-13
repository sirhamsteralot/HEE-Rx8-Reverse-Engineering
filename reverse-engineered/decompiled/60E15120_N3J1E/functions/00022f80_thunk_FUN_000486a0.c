/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_000486a0 [high]: 6-byte body: word 0xd355 = `mov.l @(0x230d8,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x230d8 = 0x000486a0 (ROM-verified, big-endian) (ROM-verified at 0x00022f80). Direct tail-jump to `FUN_000486a0` 0x000486a0; callers in callgraph: 0x0001102a. Upstream name `thunk_FUN_000486a0` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00022f80; body bytes: 6; decompiled */

void jump_to_FUN_000486a0(void)

{
  FUN_000486a0();
  return;
}


