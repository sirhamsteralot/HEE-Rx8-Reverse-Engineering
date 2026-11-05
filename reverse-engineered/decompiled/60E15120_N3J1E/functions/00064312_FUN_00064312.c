/* ROM address: 0x00064312; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062c02 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00064312(void)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(&DAT_ffff87b6)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10];
  if (((uVar1 == 0) || (0x3f < uVar1)) && ((uVar1 < 0x81 || (0xbf < uVar1)))) {
    if (uVar1 == 0xc0) {
      uVar1 = FUN_00062fa0(0x50);
      return uVar1;
    }
    return uVar1;
  }
  uVar1 = FUN_00062fa0(0);
  return uVar1;
}


