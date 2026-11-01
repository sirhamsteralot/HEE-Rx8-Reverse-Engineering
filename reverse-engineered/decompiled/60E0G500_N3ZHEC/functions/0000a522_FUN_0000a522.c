/* ROM address: 0x0000a522; body bytes: 100; decompiled */

undefined4 FUN_0000a522(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined **ppuVar3;
  
  uVar1 = FUN_00009f5e(0);
  DAT_ffffa1a2 = DAT_ffffa1a2 + 1;
  if ((DAT_ffffa1a2 & 1) != 0) {
    DAT_ffffa1a0 = DAT_ffffa1a0 + 1;
    uVar2 = (uint)DAT_ffffa1a0;
    ppuVar3 = (undefined **)&DAT_0000d8f0;
    do {
      if ((uVar2 & 1) != 0) {
        uVar1 = (*(code *)(&PTR_FUN_0000d888)[*(byte *)ppuVar3])(0);
        return uVar1;
      }
      uVar2 = (uVar2 & 0xffff) >> 1;
      ppuVar3 = (undefined **)((int)ppuVar3 + 1);
    } while (ppuVar3 < &PTR_DAT_0000d8f9);
  }
  return uVar1;
}


