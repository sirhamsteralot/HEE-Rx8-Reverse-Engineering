/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00011492 [high]: 6-byte body: word 0xd31e = `mov.l @(0x63dc,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x63dc = 0x00011492 (ROM-verified, big-endian) (ROM-verified at 0x00006360). Direct tail-jump to `FUN_00011492` 0x00011492; callers in callgraph: 0x00009f4c. Upstream name `thunk_FUN_00011492` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00006360; body bytes: 6; decompiled */

void jump_to_FUN_00011492(void)

{
  FUN_00011492();
  return;
}


