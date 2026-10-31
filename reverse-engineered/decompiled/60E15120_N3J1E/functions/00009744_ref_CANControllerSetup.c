/* ROM address: 0x00009744; body bytes: 274; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009744 (274 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_CANControllerSetup(char param_1,undefined4 *param_2,byte param_3)

{
  undefined2 *puVar1;
  uint uVar2;
  
  if (param_1 == '\0') {
    ref_canControllerInitSomething__(0);
    ref_HCANRegisterInit__(0);
    puVar1 = (undefined2 *)ref_getHCANRegisterAddress(0,&HCAN0_BCR_W);
    *puVar1 = 0x803e;
    ref_set_MCR_bits2_3(0);
    ref_set_MCR_bits5_7(0);
    ref_set_MCR_bit7(0);
  }
  else {
    ref_canControllerInitSomething__(1);
    ref_HCANRegisterInit__(1);
    puVar1 = (undefined2 *)ref_getHCANRegisterAddress(1,&HCAN0_BCR_W);
    *puVar1 = 0x803e;
    ref_set_MCR_bits2_3(1,0);
    ref_set_MCR_bits5_7(1,0);
    ref_set_MCR_bit7(1,0);
  }
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      ref_setCANRegisters((int)*(char *)((int)param_2 + 5),(int)*(char *)(param_2 + 1),
                          (int)*(char *)((int)param_2 + 6),(int)*(char *)((int)param_2 + 7),*param_2
                          ,(int)*(char *)(param_2 + 3));
      uVar2 = uVar2 + 1;
      param_2 = param_2 + 4;
    } while (uVar2 < param_3);
  }
  if (param_1 == '\0') {
    ref_checkHCANRegisterStuff(0);
    puVar1 = (undefined2 *)ref_getHCANRegisterAddress(0,&HCAN0_IMR_W);
    *puVar1 = 0xfcfe;
    FUN_0000cc46(0,0);
    return;
  }
  ref_checkHCANRegisterStuff(1);
  puVar1 = (undefined2 *)ref_getHCANRegisterAddress(1,&HCAN0_IMR_W);
  *puVar1 = 0xfcfe;
  FUN_0000cc46(1,0);
  return;
}


