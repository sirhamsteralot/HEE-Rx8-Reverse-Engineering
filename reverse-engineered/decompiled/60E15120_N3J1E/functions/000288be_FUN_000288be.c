/* ROM address: 0x000288be; body bytes: 54; decompiled */

void FUN_000288be(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00026ce0();
  FUN_00027b8e();
  FUN_00027808();
  FUN_000279d8();
  FUN_00027d06();
  FUN_0002698e();
  ref_setSR(uVar1);
  return;
}


