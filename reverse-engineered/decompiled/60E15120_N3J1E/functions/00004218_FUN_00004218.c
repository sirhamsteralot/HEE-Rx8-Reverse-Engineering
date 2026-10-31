/* [EXPORT CLEANUP]
 * Indirect jump at 0x4220: target = ROM32[0x426c + r0] (table base constant at
 * 0x4224 = 0x426c). r0 is decremented by 4 before the jump and the delay slot
 * loads the next table word through r3, so consecutive calls walk a chained
 * pointer table. Entry count, terminator and incoming-register ABI are not
 * established.
 */
/* ROM address: 0x00004218; body bytes: 12; decompiled_with_warnings */

/* Unique exact-byte match to related 60E0FC00 function at 00004218 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004218(void)

{
  int in_r0;
  
                    /* WARNING: Could not recover jumptable at 0x00004220. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)&PTR_LAB_0000426c + in_r0))();
  return;
}


