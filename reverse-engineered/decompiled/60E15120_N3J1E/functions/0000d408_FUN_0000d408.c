/* [ADDITIONAL SOURCE REVIEW]
 * eeprom_mirror_magic_check [high]: If *(u16*)0xffff8000 == 0xaa55 (pool 0xd4f4) -> DAT_ffffa3fb = 1 (pool 0xd4ec); if set, call 0x9f4c -> 0x6360 -> 0x11492 (validate via 0x3e020, pool 0x11674); if ==1 write 0x55aa (pool 0xd4ea) to 0xffff8000 (pool 0xd4f0) and jmp 0x9f58 -> 0xabfa. Called from 0x6372 (pool 0x63e8) <- ref_getSensorStuff__ 0x60c8.
 * RAM 0xffff8000 eeprom_mirror_magic (uint16): Firmware-written magic of the E2 window 0xffff8000-0xffff80ff: 0xd44c writes 0xaa55, 0xd408 checks it and rewrites 0x55aa (pools 0xd4f4/0xd4ea, base 0xd4f0). Window holds 8-byte checksummed cells (float +0, u16 cksum +4/+6 = ~(lo16+hi16)) via 0x3dc22/0x3dcd0; 241 pc-relative literal refs land in 0xffff8000-0xffff80ff.
 */
/* ROM address: 0x0000d408; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000d408 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint eeprom_mirror_magic_check(void)

{
  uint uVar1;
  
  if (eeprom_mirror_magic_ffff8000 != -0x55ab) {
    DAT_ffffa3fb = 1;
  }
  if (DAT_ffffa3fb == 0) {
    jump_to_0x00006360();
  }
  if (DAT_ffffa3fb == 1) {
    eeprom_mirror_magic_ffff8000 = 0x55aa;
    uVar1 = jump_to_0x0000636c();
    return uVar1;
  }
  return (uint)DAT_ffffa3fb;
}


