/* ROM address: 0x00042968; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004219c (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00042968(void)

{
  uint uVar1;
  
  if (DAT_ffffc995 == '\x01') {
    dtc_set_fault_x0(5,1);
  }
  else if (DAT_ffffc994 == '\x01') {
    dtc_set_fault_x0(5,2);
  }
  if (DAT_ffffc997 == '\x01') {
    uVar1 = dtc_set_fault_x0(6,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc996;
    if (uVar1 == 1) {
      uVar1 = dtc_set_fault_x0(6,2);
    }
  }
  return uVar1;
}


