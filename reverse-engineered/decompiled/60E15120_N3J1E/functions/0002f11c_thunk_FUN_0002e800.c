/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_0002e800 [high]: 6-byte body: word 0xd310 = `mov.l @(0x2f160,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x2f160 = 0x0002e800 (ROM-verified, big-endian) (ROM-verified at 0x0002f11c). Direct tail-jump to `FUN_0002e800` 0x0002e800; callers in callgraph: 0x0001102a. Upstream name `thunk_FUN_0002e800` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x0002f11c; body bytes: 6; decompiled */

void jump_to_FUN_0002e800(void)

{
  FUN_0002e800();
  return;
}


