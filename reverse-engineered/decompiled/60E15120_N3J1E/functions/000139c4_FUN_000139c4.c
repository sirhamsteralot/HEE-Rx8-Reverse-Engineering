/* [ADDITIONAL SOURCE REVIEW]
 * knock_retard_learn_to_eeprom [high]: When DAT_ffffa73f set: filters knock_retard_ffffa734 toward EEPROM 0xffff8038 (rx8_first_order_filter 0.0039/1e-05), clamps via 0x13bd2, writes back with ref_updateMemoryAtAddress_float.
 * RAM 0xffffa73f knock_seen_learn_trigger (uint8): When set, 0x139c4 learns the current retard into EEPROM 0xffff8038.
 */
/* ROM address: 0x000139c4; body bytes: 62; decompiled */

uint knock_retard_learn_to_eeprom(void)

{
  uint uVar1;
  float fVar2;
  undefined4 uVar3;
  
  if (knock_seen_learn_trigger_ffffa73f == 1) {
    fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff8038);
    fVar2 = rx8_first_order_filter(knock_retard_ffffa734,fVar2,0.0039,1e-05);
    uVar3 = knock_retard_clamp(fVar2);
    uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(uVar3,&DAT_ffff8038);
    return uVar1;
  }
  return (uint)knock_seen_learn_trigger_ffffa73f;
}


