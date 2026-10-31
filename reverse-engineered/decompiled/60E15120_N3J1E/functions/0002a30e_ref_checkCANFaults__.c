/* ROM address: 0x0002a30e; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002aa62 (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_checkCANFaults__(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0000de46();
  ref_EBCMCommEval();
  FUN_0000df08();
  FUN_0000df6a();
  FUN_0000dfb2();
  FUN_0003819e();
  FUN_0002b8fe();
  ref_CANRX216TimeoutCount();
  FUN_0002913e();
  FUN_00032da0();
  FUN_0002b264();
  ref_canRX4B1Timer();
  FUN_0002b992();
  FUN_000547ee();
  ref_setSR(uVar1);
  return;
}


