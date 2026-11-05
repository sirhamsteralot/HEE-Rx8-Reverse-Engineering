/* ROM address: 0x000606be; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005efae (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000606be(void)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(&DAT_ffff87b6)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10];
  if ((uVar1 != 0x50) && (uVar1 != 0)) {
    return uVar1;
  }
  FUN_00062570(8);
  FUN_0006381c();
  uVar1 = FUN_000628d6();
  return uVar1;
}


