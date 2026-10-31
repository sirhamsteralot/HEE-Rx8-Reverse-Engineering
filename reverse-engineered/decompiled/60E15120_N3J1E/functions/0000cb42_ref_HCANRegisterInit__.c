/* ROM address: 0x0000cb42; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000cb42 (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_HCANRegisterInit__(undefined4 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)ref_getHCANRegisterAddress(param_1,&HCAN0_TXPR_W);
  *puVar1 = 0;
  puVar1 = (undefined2 *)ref_getHCANRegisterAddress(param_1,&HCAN0_TXCR_W);
  *puVar1 = 0;
  puVar1 = (undefined2 *)ref_getHCANRegisterAddress(param_1,&HCAN0_TXACK_W);
  *puVar1 = 0xfeff;
  puVar1 = (undefined2 *)ref_getHCANRegisterAddress(param_1,&HCAN0_ABACK_W);
  *puVar1 = 0xfeff;
  puVar1 = (undefined2 *)ref_getHCANRegisterAddress(param_1,&HCAN0_RXPR_W);
  *puVar1 = 0xffff;
  puVar1 = (undefined2 *)ref_getHCANRegisterAddress(param_1,&HCAN0_RFPR_W);
  *puVar1 = 0xffff;
  puVar1 = (undefined2 *)ref_getHCANRegisterAddress(param_1,&HCAN0_UMSR_W);
  *puVar1 = 0xffff;
  puVar1 = (undefined2 *)ref_getHCANRegisterAddress(param_1,&HCAN0_IRR_W);
  *puVar1 = 0xff13;
  return;
}


