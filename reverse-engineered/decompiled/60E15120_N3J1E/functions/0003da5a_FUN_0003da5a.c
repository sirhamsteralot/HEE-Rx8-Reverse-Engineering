/* ROM address: 0x0003da5a; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003dfe2 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0003da5a(void)

{
  uint uVar1;
  
  if (DAT_ffffc635 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x58,1);
    return uVar1;
  }
  if (DAT_ffffc636 == 1) {
    uVar1 = dtc_set_fault_x0(0x58,2);
    return uVar1;
  }
  return (uint)DAT_ffffc636;
}


