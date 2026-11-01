/* ROM address: 0x000672a0; body bytes: 116; decompiled */

undefined4 FUN_000672a0(uint param_1)

{
  char cVar1;
  ushort uVar2;
  short *psVar3;
  
  cVar1 = '\0';
  uVar2 = 0;
  psVar3 = (short *)(&PTR_PTR_0007ecd0)[param_1 & 0xffff];
  while( true ) {
    if (*psVar3 == -1) {
      return 0;
    }
    if (0x32 < uVar2) break;
    if (*psVar3 != -2) {
      cVar1 = FUN_00060c1c((int)*psVar3);
    }
    if (cVar1 == '\x01') {
      return 1;
    }
    psVar3 = psVar3 + 1;
    uVar2 = uVar2 + 1;
  }
  return 0;
}


