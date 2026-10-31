/* ROM address: 0x00030104; body bytes: 34; decompiled */

uint FUN_00030104(void)

{
  uint uVar1;
  undefined4 extraout_fr0;
  
  uVar1 = (uint)DAT_ffff9f8c;
  if (uVar1 == 1) {
    uVar1 = lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&PTR_DAT_0006aab0);
    DAT_ffffbe7c = extraout_fr0;
  }
  return uVar1;
}


