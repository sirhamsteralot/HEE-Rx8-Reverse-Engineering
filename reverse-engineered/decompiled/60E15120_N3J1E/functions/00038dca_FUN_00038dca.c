/* ROM address: 0x00038dca; body bytes: 72; decompiled */

void FUN_00038dca(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_initLTFTStuff_();
  ref_initFuelCutStuff();
  FUN_0004ad30();
  FUN_0004ad8c();
  FUN_0003a4be();
  ref_setFuelingRequestPointer();
  FUN_0003c106();
  o2_channel_filter_update();
  FUN_00043bb0();
  ref_setSR(uVar1);
  return;
}


