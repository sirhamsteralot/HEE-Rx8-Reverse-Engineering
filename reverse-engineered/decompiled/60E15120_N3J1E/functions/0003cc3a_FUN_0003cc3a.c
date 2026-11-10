/* ROM address: 0x0003cc3a; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003d192 (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0003cc3a(void)

{
  uint uVar1;
  
  if (DAT_ffffc5e9 == '\x01') {
    dtc_set_fault_x0(0x11,1);
  }
  else if (DAT_ffffc5eb == 1) {
    dtc_set_fault_x0(0x11,2);
  }
  if (DAT_ffffc5ea == '\x01') {
    uVar1 = dtc_set_fault_x0(0x12,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc5eb;
    if (uVar1 == 1) {
      uVar1 = dtc_set_fault_x0(0x12,2);
    }
  }
  return uVar1;
}


