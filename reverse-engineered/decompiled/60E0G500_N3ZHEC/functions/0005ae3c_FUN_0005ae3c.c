/* ROM address: 0x0005ae3c; body bytes: 104; decompiled */

int FUN_0005ae3c(void)

{
  int iVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  
  FUN_0005afa6();
  ppuVar3 = &PTR_FUN_0005fe40;
  do {
    puVar4 = ppuVar3[1];
    iVar1 = FUN_0003eb24(&DAT_ffff9138 + (int)puVar4 * 8,0);
    iVar2 = (*(code *)*ppuVar3)(iVar1);
    if (iVar2 != iVar1) {
      FUN_0003ebe0(&DAT_ffff9138 + (int)puVar4 * 8);
      iVar2 = FUN_0005b1dc(puVar4);
    }
    ppuVar3 = ppuVar3 + 2;
  } while (ppuVar3 < &DAT_0005fe80);
  return iVar2;
}


