/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00025438 [high]: 6-byte body: word 0xd30b = `mov.l @(0x22278,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x22278 = 0x00025438 (ROM-verified, big-endian) (ROM-verified at 0x00022248). Direct tail-jump to `FUN_00025438` 0x00025438; callers in callgraph: 0x0001102a. Upstream name `thunk_FUN_00025438` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00022248; body bytes: 6; decompiled */

void jump_to_FUN_00025438(void)

{
  FUN_00025438();
  return;
}


