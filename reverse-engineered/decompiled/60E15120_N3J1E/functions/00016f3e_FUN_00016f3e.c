/* ROM address: 0x00016f3e; body bytes: 66; decompiled */

void FUN_00016f3e(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  DAT_ffffa8e4 = DAT_ffffa8e4 + 1;
  if (7 < DAT_ffffa8e4) {
    FUN_0001702c();
    FUN_00016cc4();
    DAT_ffffa8e4 = 0;
  }
  FUN_0001722e();
  ref_setSR(uVar1);
  return;
}


