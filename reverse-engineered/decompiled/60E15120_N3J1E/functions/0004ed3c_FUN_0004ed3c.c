/* [ADDITIONAL SOURCE REVIEW]
 * candidate_pd7_condition_calc [high]: Writes byte 0xffffcfbc (pool 0x4edd0): 0 when 0xffffcfc1 == 1 (pool 0x4edd2); otherwise 1 when 0xffffcfbe == 1 (pool 0x4edce) and u16 0xffffcfaa >= u16 0xffffcfa6 (pools 0x4edd4/0x4edd6, cmp/hs at 0x4ed62); otherwise 1 when 0xffffd15c == 1 (pool 0x4edd8, cmp/eq at 0x4ed6e). The two non-cranking terms belong to the neighbouring relay logic, not to this subsystem.
 */
/* ROM address: 0x0004ed3c; body bytes: 68; decompiled */

uint candidate_pd7_condition_calc(void)

{
  uint uVar1;
  
  if (DAT_ffffcfc1 == '\x01') {
    pd7_relay_condition_ffffcfbc = 0;
    uVar1 = 1;
  }
  else if (((DAT_ffffcfbe == '\x01') &&
           (uVar1 = (uint)DAT_ffffcfaa, (uint)(int)DAT_ffffcfa6 <= uVar1)) ||
          (uVar1 = (uint)cranking_in_progress_ffffd15c, uVar1 == 1)) {
    pd7_relay_condition_ffffcfbc = 1;
  }
  else {
    pd7_relay_condition_ffffcfbc = 0;
  }
  return uVar1;
}


