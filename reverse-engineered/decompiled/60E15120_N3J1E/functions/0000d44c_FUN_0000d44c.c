/* [ADDITIONAL SOURCE REVIEW]
 * eeprom_mirror_magic_init [high]: If DAT_ffffa3fb == 1 call 0x9f52 -> 0x6366 -> 0x113b8 (init fan-out); then write 0xaa55 (pool 0xd4f4) to 0xffff8000 (pool 0xd4f0). Called from ref_mainInit__ 0x61a8 (pool 0x6288).
 */
/* ROM address: 0x0000d44c; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000d44c (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint eeprom_mirror_magic_init(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffa3fb;
  if (uVar1 == 1) {
    uVar1 = jump_to_0x00006366();
    eeprom_mirror_magic_ffff8000 = 0xaa55;
  }
  return uVar1;
}


