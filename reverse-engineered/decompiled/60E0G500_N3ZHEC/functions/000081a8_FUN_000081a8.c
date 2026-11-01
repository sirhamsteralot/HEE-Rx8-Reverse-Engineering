/* ROM address: 0x000081a8; body bytes: 192; decompiled */

void FUN_000081a8(void)

{
  ushort uVar1;
  byte bVar2;
  undefined *puVar3;
  undefined **ppuVar4;
  
  bVar2 = 0;
  ppuVar4 = &PTR_DAT_0000d7d4;
  puVar3 = &DAT_ffffa004;
  do {
    puVar3[0x13] = 0;
    puVar3[0x14] = 0;
    uVar1 = DAT_fffff66c;
    DAT_fffff66c = ~*(ushort *)(ppuVar4 + 2) & uVar1;
    FUN_0000a8a4(*ppuVar4,0);
    bVar2 = bVar2 + 1;
    ppuVar4 = ppuVar4 + 3;
    puVar3 = puVar3 + 0x18;
  } while (bVar2 < 6);
  bVar2 = DAT_fffff459;
  DAT_fffff459 = bVar2 & 0xf8 | 1;
  bVar2 = DAT_fffff459;
  DAT_fffff459 = bVar2 & 0x8f | 0x10;
  bVar2 = DAT_fffff458;
  DAT_fffff458 = bVar2 & 0xf8 | 1;
  bVar2 = DAT_fffff458;
  DAT_fffff458 = bVar2 & 0x8f | 0x10;
  bVar2 = DAT_fffff45b;
  DAT_fffff45b = bVar2 & 0xf8 | 1;
  bVar2 = DAT_fffff45b;
  DAT_fffff45b = bVar2 & 0x8f | 0x10;
  uVar1 = DAT_fffff462;
  DAT_fffff462 = uVar1 & 0xfffe;
  uVar1 = DAT_fffff462;
  DAT_fffff462 = uVar1 & 0xfffd;
  uVar1 = DAT_fffff462;
  DAT_fffff462 = uVar1 & 0xfffb;
  uVar1 = DAT_fffff462;
  DAT_fffff462 = uVar1 & 0xfff7;
  uVar1 = DAT_fffff462;
  DAT_fffff462 = uVar1 & 0xffef;
  uVar1 = DAT_fffff462;
  DAT_fffff462 = uVar1 & 0xffdf;
  return;
}


