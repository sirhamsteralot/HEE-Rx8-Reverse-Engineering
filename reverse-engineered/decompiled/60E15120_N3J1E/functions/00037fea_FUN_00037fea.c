/* ROM address: 0x00037fea; body bytes: 116; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003800a) */
/* WARNING: Removing unreachable block (ram,0x00038016) */
/* WARNING: Removing unreachable block (ram,0x0003801c) */
/* WARNING: Removing unreachable block (ram,0x00038028) */
/* Unique exact-byte match to related 60E0FC00 function at 0003870a (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00037fea(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if (DAT_ffffc49e == '\x01') {
    DAT_ffffc49e = FUN_000378dc(0,0xff,4);
  }
  DAT_ffffc49d = 0;
  ref_setSR(uVar1);
  return;
}


