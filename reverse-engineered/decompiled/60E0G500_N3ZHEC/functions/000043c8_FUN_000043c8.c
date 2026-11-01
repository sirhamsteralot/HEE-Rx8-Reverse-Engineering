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


