/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffcfb9 key_on_latch_cfb9 (uint8): = (0xffff9ec8 & 1) != 0 copied by 0x4e7da; callers 0x38a18/0x390fc.
 */
/* ROM address: 0x0004e7da; body bytes: 40; decompiled */

bool FUN_0004e7da(void)

{
  key_on_latch_cfb9_ffffcfb9 = (vehicle_inputs_pfdr_latch_ffff9ec8 & 1) != 0;
  return key_on_latch_cfb9_ffffcfb9;
}


