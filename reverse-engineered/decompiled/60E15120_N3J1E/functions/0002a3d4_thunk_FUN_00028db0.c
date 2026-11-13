/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00028db0 [high]: 6-byte body: word 0xd346 = `mov.l @(0x2a4f0,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x2a4f0 = 0x00028db0 (ROM-verified, big-endian) (ROM-verified at 0x0002a3d4). Direct tail-jump to `FUN_00028db0` 0x00028db0; callers in callgraph: 0x000113b8, 0x0003de70. Upstream name `thunk_FUN_00028db0` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x0002a3d4; body bytes: 6; decompiled */

void jump_to_FUN_00028db0(void)

{
  FUN_00028db0();
  return;
}


