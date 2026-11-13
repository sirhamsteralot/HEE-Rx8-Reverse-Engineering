/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00028db8 [high]: 6-byte body: word 0xd346 = `mov.l @(0x2a4f4,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x2a4f4 = 0x00028db8 (ROM-verified, big-endian) (ROM-verified at 0x0002a3da). Direct tail-jump to `FUN_00028db8` 0x00028db8; callers in callgraph: 0x0003e020. Upstream name `thunk_FUN_00028db8` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x0002a3da; body bytes: 6; decompiled */

void jump_to_FUN_00028db8(void)

{
  FUN_00028db8();
  return;
}


