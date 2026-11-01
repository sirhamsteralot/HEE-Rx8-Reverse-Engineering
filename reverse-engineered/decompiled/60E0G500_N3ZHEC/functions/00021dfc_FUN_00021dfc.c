/* ROM address: 0x00021dfc; body bytes: 180; decompiled */

void FUN_00021dfc(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x10);
  FUN_0001fd70();
  set_open_loop_flag();
  FUN_0001faf6();
  open_loop_changeover_enrichment();
  warmup_fueling_compensation();
  FUN_00020f44();
  FUN_00021138();
  FUN_00020f34();
  FUN_000313b8();
  FUN_0001db18();
  FUN_0001d018();
  FUN_0001e360();
  FUN_0001e41e();
  FUN_0001e4fc();
  FUN_0001e588();
  FUN_0001ede0();
  maf_operating_range();
  FUN_0001f0f4();
  FUN_0001f5ac();
  FUN_0001f702();
  FUN_0001f648();
  FUN_0001f78c();
  FUN_0001f852();
  FUN_0001f99a();
  FUN_000196ec();
  fuel_cut_rpm_condition();
  rev_limit_conditionals();
  FUN_00003934(uVar1);
  return;
}


