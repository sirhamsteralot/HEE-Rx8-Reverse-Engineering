/* [ADDITIONAL SOURCE REVIEW]
 * vehicle_inputs_sticky_update [high]: Sticky update of the input latches: 0xffff9ec8 = (prev 0xffff9ed8 | PFDR_W) & 0xffff9ec8 | prev & PFDR_W (pools 0x684a=0xf74e, 0x6850=0xffff9ed8, 0x6854=0xffff9ec8); same for PHDR_W 0xfffff72c (pool 0x684c=0xf72c) -> 0xffff9eca (pools 0x685c/0x6858); three expander channels via 0x70ac -> 0xffff9ecc/9ecd/9ece.
 * RAM 0xffff9ed8 vehicle_inputs_pfdr_prev (uint8): mov.l pool 0x6850 in 0x6744 and 0x6796; previous PFDR latch used in the edge-detect update in 0x6796.
 * RAM 0xffff9eda vehicle_inputs_phdr_prev (uint8): mov.l pool 0x6858 in 0x6744 and 0x6796; previous PHDR latch used in 0x6796.
 */
/* ROM address: 0x00006796; body bytes: 172; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00006796 (172 bytes). Names prefixed ref_
   are inherited hypotheses. */

void vehicle_inputs_sticky_update(void)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  
  uVar2 = PFDR_W;
  vehicle_inputs_pfdr_latch_ffff9ec8 = (vehicle_inputs_pfdr_prev_ffff9ed8 | uVar2) & vehicle_inputs_pfdr_latch_ffff9ec8 | vehicle_inputs_pfdr_prev_ffff9ed8 & uVar2;
  uVar1 = PHDR_W;
  vehicle_inputs_phdr_latch_ffff9eca = (vehicle_inputs_phdr_prev_ffff9eda | uVar1) & vehicle_inputs_phdr_latch_ffff9eca | vehicle_inputs_phdr_prev_ffff9eda & uVar1;
  vehicle_inputs_pfdr_prev_ffff9ed8 = uVar2;
  vehicle_inputs_phdr_prev_ffff9eda = uVar1;
  bVar3 = sci0_gpio_expander_read(0);
  DAT_ffff9ecc = (DAT_ffff9edc | bVar3) & DAT_ffff9ecc | DAT_ffff9edc & bVar3;
  DAT_ffff9edc = bVar3;
  bVar3 = sci0_gpio_expander_read(1);
  DAT_ffff9ecd = (DAT_ffff9edd | bVar3) & DAT_ffff9ecd | DAT_ffff9edd & bVar3;
  DAT_ffff9edd = bVar3;
  bVar3 = sci0_gpio_expander_read(2);
  DAT_ffff9ece = (DAT_ffff9ede | bVar3) & DAT_ffff9ece | DAT_ffff9ede & bVar3;
  DAT_ffff9ede = bVar3;
  DAT_ffff9ed0 = DAT_ffff9ed4 & DAT_ffff9ed0 | DAT_ffff9ed4;
  return;
}


