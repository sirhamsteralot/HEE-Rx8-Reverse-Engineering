/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffcfb8 key_on_latch_cfb8 (uint8): = (0xffff9ec8 & 1) != 0 copied by 0x4e7aa (pool 0x4e874=0xf74e for PFDR_W 0xfffff74e).
 */
/* ROM address: 0x0004e7aa; body bytes: 48; decompiled */

bool FUN_0004e7aa(void)

{
  ushort uVar1;
  
  uVar1 = PFDR_W;
  key_on_latch_cfb8_ffffcfb8 = (uVar1 & 1) != 0;
  return key_on_latch_cfb8_ffffcfb8;
}


