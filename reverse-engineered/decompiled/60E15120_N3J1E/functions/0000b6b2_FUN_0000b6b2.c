/* ROM address: 0x0000b6b2; body bytes: 386; decompiled */

void FUN_0000b6b2(void)

{
  ushort uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined4 local_2c;
  undefined4 auStack_28 [3];
  
  if (DAT_ffffa322 != '\0') {
    DAT_ffffa321 = 0;
    if (DAT_ffffa31e < (byte)(&DAT_ffffa31a)[DAT_ffffa31c]) {
      DMAC_DMATCR3_L = 2;
      DMAC_SAR3_L = 0xfffff00d;
      DMAC_DAR3_L = &DAT_ffffa2a2 + DAT_ffffa31e;
      DMAC_CHCR3_L._2_2_ = 0x100;
      DMAC_CHCR3_L = 0x40100;
      DMAC_DMATCR2_L = 2;
      DMAC_SAR2_L = &DAT_ffffa22a + (uint)DAT_ffffa31e * 2 + (uint)DAT_ffffa31c * 0x3c;
      DMAC_DAR2_L = 0xfffff00b;
      DMAC_CHCR2_L._2_2_ = 0x1000;
      DMAC_CHCR2_L = 0x31000;
      bVar3 = SCI_SSR1_B;
      SCI_SSR1_B = bVar3 & 0x87 | 0x80;
      bVar3 = SCI_SCR1_B;
      SCI_SCR1_B = bVar3 & 0xb | 0xf0;
      uVar1 = DMAC_DMAOR_W;
      DMAC_DMAOR_W = uVar1 & 0xfff8 | 1;
      uVar2 = DMAC_CHCR3_L;
      DMAC_CHCR3_L = uVar2 & 0xfffffff9 | 1;
      uVar2 = DMAC_CHCR2_L;
      DMAC_CHCR2_L = uVar2 & 0xfffffff9 | 1;
      DAT_ffffa31e = DAT_ffffa31e + 1;
    }
    else {
      ref_setSR_PARAM(auStack_28,0xe0);
      ref_setRegister_REG_BIT_VAL(0xfffff72c,0x100,1);
      FUN_00002064(auStack_28[0]);
      ref_setSR_PARAM(&local_2c,0xe0);
      ref_setRegister_REG_BIT_VAL(0xfffff72c,0x80);
      FUN_00002064(local_2c);
      DAT_ffffa322 = '\0';
      iVar4 = 0;
      for (iVar5 = 0; iVar5 < (int)(uint)DAT_ffffa31e; iVar5 = iVar5 + 1) {
        *(undefined2 *)((int)&DAT_ffffa2de + iVar4) = *(undefined2 *)((int)&DAT_ffffa2a2 + iVar4);
        iVar4 = iVar4 + 2;
      }
      if (DAT_ffffa228 == '\0') {
        DAT_ffffa228 = '\x01';
      }
      else {
        DAT_ffffa228 = '\x02';
      }
      DAT_ffffa320 = 0;
      DAT_ffffa31c = DAT_ffffa31c + 1;
      if (1 < DAT_ffffa31c) {
        DAT_ffffa31c = 0;
      }
      DAT_ffffa31f = DAT_ffffa31f + -1;
      if (DAT_ffffa31f != '\0') {
        sh_busy_wait_count_times_8(4);
        FUN_0000bccc();
      }
    }
  }
  return;
}


