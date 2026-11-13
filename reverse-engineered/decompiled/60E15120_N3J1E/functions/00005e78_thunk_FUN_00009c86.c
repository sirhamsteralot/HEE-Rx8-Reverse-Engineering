/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_can_rx_isr_handler [high]: 6-byte body: word 0xd30f = `mov.l @(0x5eb8,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x5eb8 = 0x00009c86 (ROM-verified, big-endian) (ROM-verified at 0x00005e78). Direct tail-jump to `can_rx_isr_handler` 0x00009c86; no callgraph callers (vector/dispatch-table entry only). Upstream name `thunk_FUN_00009c86` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00005e78; body bytes: 6; decompiled */

void jump_to_can_rx_isr_handler(void)

{
  can_rx_isr_handler();
  return;
}


