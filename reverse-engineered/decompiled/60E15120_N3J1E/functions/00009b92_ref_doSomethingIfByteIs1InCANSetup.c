/* ROM address: 0x00009b92; body bytes: 106; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009b92 (106 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_doSomethingIfByteIs1InCANSetup(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort *puVar3;
  ushort uVar5;
  undefined2 *puVar4;
  undefined2 uVar6;
  
  uVar2 = sh_raise_interrupt_mask_return_previous(0x90);
  puVar3 = (ushort *)FUN_0000cee8((int)*(char *)(param_1 + 5),&HCAN0_TXPR_W);
  uVar1 = *puVar3;
  uVar5 = FUN_0000cf12((int)*(char *)(param_1 + 5));
  if ((uVar5 & uVar1) != 0) {
    puVar4 = (undefined2 *)FUN_0000cee8((int)*(char *)(param_1 + 5),&HCAN0_ABACK_W);
    uVar6 = FUN_0000cf12((int)*(char *)(param_1 + 5));
    *puVar4 = uVar6;
    puVar4 = (undefined2 *)FUN_0000cee8((int)*(char *)(param_1 + 5),&HCAN0_TXCR_W);
    uVar6 = FUN_0000cf12((int)*(char *)(param_1 + 5));
    *puVar4 = uVar6;
  }
  ref_setSR(uVar2);
  return;
}


