/* ROM address: 0x00020df0; body bytes: 80; decompiled */

void FUN_00020df0(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  uVar2 = param_1 & 0xff;
  if ((((uVar2 == 0) || (uVar2 == 0xc)) || (uVar2 == 6)) || (uVar2 == 0x12)) {
    candidate_fuel_cut_arbitration(param_1);
    ref_fuelCutSomethingSomething(param_1);
  }
  FUN_0002ca10(param_1);
  FUN_0000f4d8(param_1);
  ref_setSR(uVar1);
  return;
}


