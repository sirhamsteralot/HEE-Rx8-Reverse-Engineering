/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00010fa8 [high]: 6-byte body: word 0xd34f = `mov.l @(0x104c8,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x104c8 = 0x00010fa8 (ROM-verified, big-endian) (ROM-verified at 0x0001038a). Direct tail-jump to `FUN_00010fa8` 0x00010fa8; callers in callgraph: 0x000142a4. Upstream name `thunk_FUN_00010fa8` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x0001038a; body bytes: 6; decompiled */

void jump_to_FUN_00010fa8(void)

{
  FUN_00010fa8();
  return;
}


