/* [EXPORT CLEANUP]
 * jmp @r4 at 0x1092 is an indirect tail jump through register r4, preceded only
 * by a PC-relative constant load into r15. No ROM switch or index data is read,
 * so the decompiler warning is expected; the parameter formerly named
 * UNRECOVERED_JUMPTABLE has been renamed indirect_target. The producer of r4
 * is not established in this dump.
 */
/* ROM address: 0x00001090; body bytes: 6; decompiled_with_warnings */

void FUN_00001090(code *indirect_target)

{
                    /* WARNING: Could not recover jumptable at 0x00001092. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*indirect_target)();
  return;
}


