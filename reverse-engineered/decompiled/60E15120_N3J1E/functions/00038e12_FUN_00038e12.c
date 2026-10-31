/* ROM address: 0x00038e12; body bytes: 210; decompiled */

void FUN_00038e12(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0003d7be();
  FUN_0004591a();
  FUN_0004595a();
  FUN_00045d90();
  FUN_00045e96();
  FUN_00045b3c();
  FUN_00045c42();
  ref_setSR(uVar1);
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0004e802();
  ref_interestingFunc1();
  FUN_0004f510();
  FUN_0004f59a();
  FUN_0004f640();
  FUN_00052890();
  FUN_0004f730();
  FUN_0004f79e();
  FUN_0004e7aa();
  FUN_0004e828();
  FUN_0004ede2();
  FUN_0004ee4a();
  FUN_0004ef86();
  FUN_0003a0ec();
  FUN_0003ae70();
  FUN_0003aeae();
  FUN_0003af10();
  FUN_0003b02c();
  FUN_0003b110();
  FUN_0003b1b2();
  FUN_000415e4();
  FUN_0004162e();
  FUN_00045030();
  ref_setSR(uVar1);
  return;
}


