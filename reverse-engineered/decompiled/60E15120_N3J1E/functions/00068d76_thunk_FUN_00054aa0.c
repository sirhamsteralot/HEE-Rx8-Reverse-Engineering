/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00054aa0 [high]: 6-byte body: word 0xd30a = `mov.l @(0x68da0,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x68da0 = 0x00054aa0 (ROM-verified, big-endian) (ROM-verified at 0x00068d76). Direct tail-jump to `FUN_00054aa0` 0x00054aa0; no callgraph callers (vector/dispatch-table entry only). Upstream name `thunk_FUN_00054aa0` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00068d76; body bytes: 6; decompiled */

void jump_to_FUN_00054aa0(void)

{
  FUN_00054aa0();
  return;
}


