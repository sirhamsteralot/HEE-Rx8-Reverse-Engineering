/* [EXPORT CLEANUP]
 * Jump-table dispatch at 0x43e6 recovered from ROM data. Cases r1 = 0x00-0x1f
 * (range checks at 0x43ca-0x43d2); index byte at ROM[0x43a8 + r1] (32 signed
 * bytes at 0x43a8-0x43c7), target = 0x4446 + (signed)byte. Cases 0x00-0x17 land
 * in a shar r0 sled (ROM 0x4414-0x4440, byte pair 40 21 repeated, ending in
 * rts at 0x4442; the sled lies outside this export's decoded instructions),
 * giving an arithmetic right shift of r0 by r1 (0-23). Cases 0x18-0x1f land
 * in byte/word manipulation stubs at 0x4446-0x44b8. Consistent with a
 * variable-shift helper plus extension operations; stub semantics were not
 * re-derived.
 */
/* ROM address: 0x000043c8; body bytes: 66; decompiled_with_warnings */

uint FUN_000043c8(void)

{
  uint in_r0;
  uint uVar1;
  int in_r1;
  
  if (in_r1 < 0) {
    return in_r0;
  }
  if (0x1f < in_r1) {
    if ((in_r0 & 0x80000000) != 0) {
      return 0xffffffff;
    }
    return 0;
  }
  if (((in_r0 & 0x80000000) == 0) && (8 < in_r1)) {
                    /* WARNING: Could not recover jumptable at 0x000044f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)((undefined *)0x450a + (char)(&switchD_000044f6::switchdataD_000044c0)[in_r1])
            )();
    return uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x000043e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(&LAB_00004446 + (char)(&DAT_000043a8)[in_r1]))();
  return uVar1;
}


