/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_e2ram_learned_table_validate [high]: 6-byte body: word 0xd34d = `mov.l @(0x28ac8,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x28ac8 = 0x000270aa (ROM-verified, big-endian) (ROM-verified at 0x00028992). Direct tail-jump to `e2ram_learned_table_validate` 0x000270aa; callers in callgraph: 0x0003e020. Upstream name `thunk_FUN_000270aa` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00028992; body bytes: 6; decompiled */

void jump_to_e2ram_learned_table_validate(void)

{
  FUN_000270aa();
  return;
}


