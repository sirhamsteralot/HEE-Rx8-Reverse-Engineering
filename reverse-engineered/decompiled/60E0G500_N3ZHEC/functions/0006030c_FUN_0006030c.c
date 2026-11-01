/* ROM address: 0x0006030c; body bytes: 106; decompiled */

bool FUN_0006030c(ushort param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  undefined **ppuVar5;
  
  ppuVar5 = &PTR_FUN_00060c9c;
  uVar3 = 0x80;
  uVar2 = 0;
  bVar4 = 0;
  do {
    cVar1 = (*(code *)*ppuVar5)();
    if (cVar1 == '\0') {
      uVar2 = uVar2 | uVar3;
    }
    uVar3 = uVar3 >> 1;
    bVar4 = bVar4 + 1;
    ppuVar5 = ppuVar5 + 1;
  } while (bVar4 < 8);
  return (uVar2 & (byte)(&DAT_0007de46)[param_1]) != (uint)(byte)(&DAT_0007de46)[param_1];
}


