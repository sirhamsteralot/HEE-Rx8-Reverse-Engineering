/* ROM address: 0x00009890; body bytes: 262; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009890 (262 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_placeCANRX(int param_1)

{
  ushort uVar1;
  ushort *puVar2;
  ushort uVar5;
  undefined4 uVar3;
  undefined2 *puVar4;
  undefined2 uVar6;
  undefined4 uVar7;
  uint uVar8;
  
  puVar2 = (ushort *)FUN_0000cee8((int)*(char *)(param_1 + 5),&HCAN0_RXPR_W);
  uVar1 = *puVar2;
  uVar5 = FUN_0000cf12((int)*(char *)(param_1 + 5));
  if ((uVar5 & uVar1) == 0) {
    uVar7 = 1;
  }
  else {
    uVar3 = sh_raise_interrupt_mask_return_previous(0x90);
    puVar4 = (undefined2 *)FUN_0000cee8((int)*(char *)(param_1 + 5),&HCAN0_UMSR_W);
    uVar6 = FUN_0000cf12((int)*(char *)(param_1 + 5));
    *puVar4 = uVar6;
    FUN_0000cca4((int)*(char *)(param_1 + 5),(int)*(char *)(param_1 + 6),0,
                 *(undefined4 *)(param_1 + 8));
    uVar7 = 2;
    uVar8 = 0;
    do {
      puVar2 = (ushort *)FUN_0000cee8((int)*(char *)(param_1 + 5),&HCAN0_UMSR_W);
      uVar1 = *puVar2;
      uVar5 = FUN_0000cf12((int)*(char *)(param_1 + 5));
      if ((uVar5 & uVar1) == 0) {
        uVar7 = 0;
        break;
      }
      puVar4 = (undefined2 *)FUN_0000cee8((int)*(char *)(param_1 + 5),&HCAN0_UMSR_W);
      uVar6 = FUN_0000cf12((int)*(char *)(param_1 + 5));
      *puVar4 = uVar6;
      FUN_0000cca4((int)*(char *)(param_1 + 5),(int)*(char *)(param_1 + 6),0,
                   *(undefined4 *)(param_1 + 8));
      uVar8 = uVar8 + 1;
    } while (uVar8 < 5);
    puVar4 = (undefined2 *)FUN_0000cee8((int)*(char *)(param_1 + 5),&HCAN0_RXPR_W);
    uVar6 = FUN_0000cf12((int)*(char *)(param_1 + 5));
    *puVar4 = uVar6;
    ref_setSR(uVar3);
  }
  return uVar7;
}


