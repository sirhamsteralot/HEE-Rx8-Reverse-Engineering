/* [ADDITIONAL SOURCE REVIEW]
 * dtc_count_ram_table [high]: counts DAT_ffffd570[0..0x8b]==1, rotor-0/1 adjust, clamp 0xff
 * RAM 0xffffd570 dtc_ram_flag_table_ffffd570 (uint8[0x8c]): PID 0x0202 counts set bytes (140 DTC slots)
 */
/* ROM address: 0x0005fb08; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e414 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint dtc_count_ram_table(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar1 = 0;
  uVar3 = 0;
  do {
    if ((&dtc_ram_flag_table_ffffd570_ffffd570)[uVar1] == '\x01') {
      uVar2 = uVar2 + 1;
      if ((uVar1 == 0) || (uVar1 == 1)) {
        uVar3 = uVar3 + 1;
      }
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x8c);
  if ((uVar3 & 0xffff) != 0) {
    uVar2 = (uVar2 - uVar3) + 1;
  }
  if (0xff < (uVar2 & 0xffff)) {
    uVar2 = 0xff;
  }
  return uVar2;
}


