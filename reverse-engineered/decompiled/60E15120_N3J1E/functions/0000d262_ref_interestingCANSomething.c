/* ROM address: 0x0000d262; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000d262 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_interestingCANSomething(void)

{
  char cVar2;
  int iVar1;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  cVar2 = can_rx_copy_mailbox_to_buffer(&DAT_0000d934);
  if ((cVar2 == '\0') && (iVar1 = FUN_00000636(&DAT_ffffa3e8), iVar1 != 0)) {
    uVar3 = 0;
  }
  return uVar3;
}


