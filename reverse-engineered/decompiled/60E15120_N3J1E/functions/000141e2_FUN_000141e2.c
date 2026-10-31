/* ROM address: 0x000141e2; body bytes: 92; decompiled */

void FUN_000141e2(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00013508();
  uVar2 = param_1 & 0xff;
  if ((((uVar2 == 0) || (uVar2 == 0xc)) || (uVar2 == 6)) || (uVar2 == 0x12)) {
    FUN_000183a0(param_1);
  }
  FUN_0002bc34();
  FUN_0002bcc0();
  FUN_00010b38(param_1);
  FUN_00010390(param_1);
  ref_setSR(uVar1);
  return;
}


