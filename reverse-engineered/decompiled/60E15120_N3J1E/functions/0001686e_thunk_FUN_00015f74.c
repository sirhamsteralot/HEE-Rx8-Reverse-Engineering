/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00015f74 [high]: 6-byte body: word 0xd322 = `mov.l @(0x168f8,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x168f8 = 0x00015f74 (ROM-verified, big-endian) (ROM-verified at 0x0001686e). Direct tail-jump to `FUN_00015f74` 0x00015f74; callers in callgraph: 0x000113b8, 0x0003de70. Upstream name `thunk_FUN_00015f74` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x0001686e; body bytes: 6; decompiled */

void jump_to_FUN_00015f74(void)

{
  FUN_00015f74();
  return;
}


