/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_0x0000636c [high]: 6-byte body: word 0xd3a5 = `mov.l @(0xa1f0,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0xa1f0 = 0x0000636c (ROM-verified, big-endian) (ROM-verified at 0x00009f58). Direct tail-jump to `0x0000636c` 0x0000636c; callers in callgraph: 0x0000d408. Upstream name `thunk_FUN_0000abfa` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00009f58; body bytes: 6; decompiled */

void jump_to_0x0000636c(void)

{
  jump_to_0x0000636c();
  return;
}


