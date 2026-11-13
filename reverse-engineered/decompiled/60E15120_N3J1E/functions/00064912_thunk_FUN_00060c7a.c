/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00060c7a [high]: 6-byte body: word 0xd333 = `mov.l @(0x649e0,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x649e0 = 0x00060c7a (ROM-verified, big-endian) (ROM-verified at 0x00064912). Direct tail-jump to `FUN_00060c7a` 0x00060c7a; callers in callgraph: 0x00061092. Upstream name `thunk_FUN_00060c7a` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00064912; body bytes: 6; decompiled */

void jump_to_FUN_00060c7a(void)

{
  FUN_00060c7a();
  return;
}


