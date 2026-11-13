/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_0000abfa [high]: 6-byte body: word 0xd31d = `mov.l @(0x63e4,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x63e4 = 0x0000abfa (ROM-verified, big-endian) (ROM-verified at 0x0000636c). Direct tail-jump to `FUN_0000abfa` 0x0000abfa; callers in callgraph: 0x00009f58. Upstream name `thunk_FUN_0000abfa` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x0000636c; body bytes: 6; decompiled */

void jump_to_FUN_0000abfa(void)

{
  FUN_0000abfa();
  return;
}


