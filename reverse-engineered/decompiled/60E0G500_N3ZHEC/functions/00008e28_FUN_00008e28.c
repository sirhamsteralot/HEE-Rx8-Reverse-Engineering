/* ROM address: 0x00008e28; body bytes: 142; decompiled */

void FUN_00008e28(byte param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = FUN_00003920(0x10);
  iVar2 = (uint)param_1 * 8;
  if ((&DAT_ffffa0dd)[iVar2] == '\0') {
    (&DAT_ffffa0dc)[iVar2] = 0;
  }
  else {
    uVar3 = (uint)param_1;
    if ((-1 < (short)(*(short *)(&PTR_DAT_0000d820)[uVar3 * 6] -
                     (*(short *)(&PTR_DAT_0000d828)[uVar3 * 6] + 3))) &&
       ((*(ushort *)(&DAT_0000d830 + uVar3 * 0x18) & *(ushort *)(&PTR_DAT_0000d82c)[uVar3 * 6]) == 0
       )) {
      FUN_0000a8a4((&PTR_DAT_0000d81c)[uVar3 * 6],0);
      (&DAT_ffffa0dc)[iVar2] = 0;
      (&DAT_ffffa0dd)[iVar2] = 0;
    }
  }
  FUN_00003934(uVar1);
  return;
}


