/* [ADDITIONAL SOURCE REVIEW]
 * immo_eeprom_key_read_kick [high]: 36 B, unique_exact_bytes to 60E0FC00 0x35124, called from task 0x114d0. Mask-0x10 critical section: e2ram_immo_key_read 0x375c0, 0x3583c (ADC-seed refresh: 0xffff8674 += ATUII_TCNT0H_W), FUN_0000e2d4(1) (fuel-cut arbitration), restore SR.
 */
/* ROM address: 0x00034a04; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00035124 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void immo_eeprom_key_read_kick(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  e2ram_immo_key_read();
  FUN_0003583c();
  fuel_cut_bitmask_build(1);
  ref_setSR(uVar1);
  return;
}


