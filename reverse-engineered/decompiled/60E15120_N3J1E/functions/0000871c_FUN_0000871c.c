/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0000871c; body bytes: 134; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000871c (134 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0000871c(byte param_1)

{
  undefined4 snapshot_crank_period_accumulator_ffff9f88;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  snapshot_crank_period_accumulator_ffff9f88 = crank_period_accumulator_ffff9f88;
  iVar5 = (uint)param_1 * 0x18;
  if ((byte)(&injector_channel_enable_flag_ffffa017)[iVar5] == 2) {
    uVar2 = sh_raise_interrupt_mask_return_previous(0x10);
    iVar3 = ref_LongFunc((&injector_zero_offset_ch0_ffffa0ac)[param_1] + *(int *)(&DAT_ffffa004 + iVar5) +
                         (&injector_latency_ch0_ffffa094)[param_1],snapshot_crank_period_accumulator_ffff9f88);
    *(int *)(&DAT_ffffa008 + iVar5) =
         *(int *)(&DAT_ffffa008 + iVar5) + *(int *)(&DAT_ffffa00c + iVar5) + iVar3 * -0xb4;
    *(int *)(&DAT_ffffa00c + iVar5) = iVar3 * 0xb4;
    uVar4 = ref_setSR(uVar2);
    return uVar4;
  }
  return (uint)(byte)(&injector_channel_enable_flag_ffffa017)[iVar5];
}


