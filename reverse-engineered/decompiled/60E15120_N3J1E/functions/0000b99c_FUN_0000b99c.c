/* ROM address: 0x0000b99c; body bytes: 460; decompiled */

undefined4 FUN_0000b99c(int param_1,int param_2,byte param_3)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  uint local_40;
  int iStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  byte bStack_24;
  
  bStack_24 = param_3;
  FUN_0000a850();
  uVar3 = 0;
  while (uVar1 = PLDR_W, (uVar1 & 0x1000) != 0) {
    sh_busy_wait_count_times_8(10);
    uVar3 = uVar3 + 1;
    if (0x5db < uVar3) {
      DAT_ffffa320 = 1;
      return 1;
    }
  }
  FUN_0000a850();
  ISR_W = 0xf7;
  ref_setSR_PARAM(&uStack_28,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff72c,0x100,0);
  FUN_00002064(uStack_28);
  ref_setSR_PARAM(&uStack_2c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff72c,0x80,0);
  FUN_00002064(uStack_2c);
  uVar3 = 0;
  do {
    uVar1 = ISR_W;
    if ((uVar1 & 8) != 0) {
      ISR_W = 0xf7;
      DAT_ffffa31e = 0;
      iStack_3c = param_2;
      iStack_38 = param_1;
      do {
        if (bStack_24 <= DAT_ffffa31e) {
          ref_setSR_PARAM(&uStack_30,0xe0);
          ref_setRegister_REG_BIT_VAL(0xfffff72c,0x100,1);
          FUN_00002064(uStack_30);
          ref_setSR_PARAM(&uStack_34,0xe0);
          ref_setRegister_REG_BIT_VAL(0xfffff72c,0x80);
          FUN_00002064(uStack_34);
          DAT_ffffa320 = 0;
          return 0;
        }
        DMAC_DMATCR3_L = 2;
        DMAC_SAR3_L = 0xfffff00d;
        DMAC_DAR3_L = iStack_3c;
        DMAC_CHCR3_L._2_2_ = 0x100;
        DMAC_CHCR3_L = 0x40100;
        DMAC_DMATCR2_L = 2;
        DMAC_SAR2_L = iStack_38;
        DMAC_DAR2_L = 0xfffff00b;
        DMAC_CHCR2_L._2_2_ = 0x1000;
        DMAC_CHCR2_L = 0x31000;
        bVar2 = SCI_SSR1_B;
        SCI_SSR1_B = bVar2 & 0x87 | 0x80;
        bVar2 = SCI_SCR1_B;
        SCI_SCR1_B = bVar2 & 0xb | 0xf0;
        uVar1 = DMAC_DMAOR_W;
        DMAC_DMAOR_W = uVar1 & 0xfff8 | 1;
        uVar3 = DMAC_CHCR3_L;
        DMAC_CHCR3_L = uVar3 & 0xfffffff9 | 1;
        uVar3 = DMAC_CHCR2_L;
        DMAC_CHCR2_L = uVar3 & 0xfffffff9 | 1;
        iStack_38 = iStack_38 + 2;
        iStack_3c = iStack_3c + 2;
        local_40 = 0;
        while (uVar1 = ISR_W, (uVar1 & 8) == 0) {
          sh_busy_wait_count_times_8(10);
          local_40 = local_40 + 1;
          if (99 < local_40) {
            DAT_ffffa320 = 1;
            return 1;
          }
        }
        ISR_W = 0xf7;
        DAT_ffffa31e = DAT_ffffa31e + 1;
      } while( true );
    }
    sh_busy_wait_count_times_8(10);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 100);
  DAT_ffffa320 = 1;
  return 1;
}


