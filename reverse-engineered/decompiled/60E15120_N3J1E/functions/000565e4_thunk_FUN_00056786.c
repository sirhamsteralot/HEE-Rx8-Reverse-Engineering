/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00056786 [high]: 4-byte body: word 0xa0cf = `bra 0x56786` + delay-slot word 0x0009 (ROM-verified at 0x000565e4). Direct tail-jump to `FUN_00056786` 0x00056786; callers in callgraph: 0x0001102a. Upstream name `thunk_FUN_00056786` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x000565e4; body bytes: 4; decompiled */

undefined4 jump_to_FUN_00056786(void)

{
  undefined4 uVar1;
  
  if (inferred_ram_c1d2_ffffc1d2_ffffc1d2 == '3') {
    uVar1 = FUN_000566f0(0);
  }
  else {
    uVar1 = FUN_000566f0(3);
  }
  DAT_ffffd1e0 = 0;
  return uVar1;
}


