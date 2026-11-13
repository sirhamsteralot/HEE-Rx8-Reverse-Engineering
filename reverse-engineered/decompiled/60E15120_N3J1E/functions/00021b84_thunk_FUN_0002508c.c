/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_0002508c [high]: 6-byte body: word 0xd317 = `mov.l @(0x21be4,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x21be4 = 0x0002508c (ROM-verified, big-endian) (ROM-verified at 0x00021b84). Direct tail-jump to `FUN_0002508c` 0x0002508c; callers in callgraph: 0x0001102a. Upstream name `thunk_FUN_0002508c` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00021b84; body bytes: 6; decompiled */

void jump_to_FUN_0002508c(void)

{
  FUN_0002508c();
  return;
}


