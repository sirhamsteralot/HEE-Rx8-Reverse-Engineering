/* ROM address: 0x0006053a; body bytes: 94; decompiled */

uint FUN_0006053a(void)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  uint uVar4;
  uint uVar5;
  short local_44 [22];
  
  psVar3 = local_44;
  uVar2 = FUN_00061d6a(0xf0,0);
  uVar5 = 0;
  uVar4 = uVar2 & 0xffff;
  if (uVar4 != 0) {
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
      uVar2 = FUN_00060154((int)sVar1,0x20);
      uVar2 = uVar2 & 0xff;
      if (uVar2 == 0) {
        uVar2 = FUN_000622cc((int)sVar1);
      }
      uVar5 = uVar5 + 1;
    } while ((uVar5 & 0xffff) < uVar4);
  }
  return uVar2;
}


