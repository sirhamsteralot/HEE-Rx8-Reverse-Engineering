/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_0x00006360 [high]: 6-byte body: word 0xd3a6 = `mov.l @(0xa1e8,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0xa1e8 = 0x00006360 (ROM-verified, big-endian) (ROM-verified at 0x00009f4c). Direct tail-jump to `0x00006360` 0x00006360; callers in callgraph: 0x0000d408. Upstream name `thunk_FUN_00011492` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00009f4c; body bytes: 6; decompiled */

void jump_to_0x00006360(void)

{
  jump_to_0x00006360();
  return;
}


