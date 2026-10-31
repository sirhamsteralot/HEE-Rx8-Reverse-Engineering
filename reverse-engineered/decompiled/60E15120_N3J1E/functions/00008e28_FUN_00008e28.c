/* ROM address: 0x00008e28; body bytes: 142; decompiled */

void FUN_00008e28(byte param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  iVar2 = (uint)param_1 * 8;
  if ((&DAT_ffffa0dd)[iVar2] == '\0') {
    (&DAT_ffffa0dc)[iVar2] = 0;
  }
  else {
    uVar3 = (uint)param_1;
    if ((-1 < (short)(*(short *)(&PTR_ATUII_OCR2A_W_0000d820)[uVar3 * 6] -
                     (*(short *)(&PTR_ATUII_TCNT2B_W_0000d828)[uVar3 * 6] + 3))) &&
       ((*(ushort *)(&DAT_0000d830 + uVar3 * 0x18) &
        *(ushort *)(&PTR_ATUII_DSTR_W_0000d82c)[uVar3 * 6]) == 0)) {
      FUN_0000a8a4((&PTR_ATUII_DCNT8I_W_0000d81c)[uVar3 * 6],0);
      (&DAT_ffffa0dc)[iVar2] = 0;
      (&DAT_ffffa0dd)[iVar2] = 0;
    }
  }
  ref_setSR(uVar1);
  return;
}


