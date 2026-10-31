/* ROM address: 0x00033d3c; body bytes: 34; decompiled */

uint FUN_00033d3c(void)

{
  uint uVar1;
  undefined4 extraout_fr0;
  
  uVar1 = (uint)engine_injectors_off_ffffa42c;
  if (uVar1 == 1) {
    uVar1 = lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&DAT_0006b008);
    DAT_ffffc100 = extraout_fr0;
  }
  return uVar1;
}


