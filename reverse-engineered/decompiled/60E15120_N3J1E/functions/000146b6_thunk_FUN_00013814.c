/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00013814 [high]: 6-byte body: word 0xd324 = `mov.l @(0x14748,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x14748 = 0x00013814 (ROM-verified, big-endian) (ROM-verified at 0x000146b6). Direct tail-jump to `FUN_00013814` 0x00013814; callers in callgraph: 0x000113b8, 0x0003de70. Upstream name `thunk_FUN_00013814` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x000146b6; body bytes: 6; decompiled */

void jump_to_FUN_00013814(void)

{
  FUN_00013814();
  return;
}


