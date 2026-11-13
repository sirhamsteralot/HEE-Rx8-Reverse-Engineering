/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00004dee [high]: 4-byte body: word 0xaff2 = `bra 0x4dee` + delay-slot word 0x0009 (ROM-verified at 0x00004e06). Direct tail-jump to `FUN_00004dee` 0x00004dee; callers in callgraph: 0x00004cb6. Upstream name `thunk_FUN_00004dee` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00004e06; body bytes: 4; decompiled */

void jump_to_FUN_00004dee(void)

{
  UBC_UBARH_W = 0x7fffffff;
  UBC_UBAMRH_W = 0x7fffffff;
  UBC_UBBR_W = 0xe8;
  UBC_UBCR_W = 0;
  return;
}


