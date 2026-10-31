/* ROM address: 0x00021186; body bytes: 120; decompiled */

void FUN_00021186(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  injector_latency_cal_lookup();
  FUN_00020bc8();
  FUN_00020c14();
  FUN_00020cf0();
  FUN_0000e444();
  FUN_00030104();
  FUN_00030126();
  FUN_000303a8();
  FUN_0001d1ca();
  FUN_00033e36();
  FUN_00033d3c();
  rev_limit_fuel_cut_init();
  FUN_000470d0();
  FUN_000429dc();
  FUN_000342b0();
  FUN_00033fc4();
  FUN_0003419c();
  ref_setSR(uVar1);
  return;
}


