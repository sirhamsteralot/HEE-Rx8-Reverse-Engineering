/* ROM address: 0x000167c0; body bytes: 174; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000165c4 (174 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_updateIdleControl__(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_000148a4();
  FUN_00016748();
  FUN_00016358();
  FUN_00016900();
  FUN_000148c4();
  FUN_00015f5c();
  FUN_00014944();
  FUN_00014baa();
  FUN_0001506c();
  FUN_00014d10();
  FUN_00014f6c();
  FUN_00016432();
  FUN_000165d6();
  FUN_00016672();
  FUN_00015ffc();
  FUN_0001617e();
  FUN_00015fa0();
  FUN_00015a40();
  FUN_00016380();
  FUN_00016720();
  FUN_0003337c();
  FUN_0003354e();
  FUN_00034650();
  FUN_00034814();
  FUN_00015a9a();
  FUN_000216f8();
  ref_setSR(uVar1);
  return;
}


