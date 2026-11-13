/* ROM address: 0x00039cf0; body bytes: 96; decompiled */

void FUN_00039cf0(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0003825a();
  FUN_0003840c();
  FUN_000384a2();
  FUN_000385f6();
  e2ram_tire_size_marker_check();
  FUN_00054426();
  FUN_00054486();
  FUN_000544c4();
  FUN_0005455e();
  FUN_000508ac();
  FUN_00051bb0();
  ref_IATTimerOperation__();
  FUN_0003d19e();
  ref_setSR(uVar1);
  return;
}


