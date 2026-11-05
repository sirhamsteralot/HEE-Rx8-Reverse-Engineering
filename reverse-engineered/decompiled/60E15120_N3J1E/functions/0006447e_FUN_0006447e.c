/* ROM address: 0x0006447e; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062d6e (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0006447e(void)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(&DAT_ffff87b6)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10];
  if ((uVar1 != 0) && (uVar1 != 0x50)) {
    return uVar1;
  }
  uVar1 = FUN_00067760();
  return uVar1;
}


