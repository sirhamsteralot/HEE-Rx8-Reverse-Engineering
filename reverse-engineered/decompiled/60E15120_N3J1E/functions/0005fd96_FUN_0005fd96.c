/* ROM address: 0x0005fd96; body bytes: 94; decompiled */

uint FUN_0005fd96(void)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  uint uVar4;
  uint uVar5;
  short local_44 [22];
  
  psVar3 = local_44;
  uVar2 = FUN_000615c6(0xf0,0);
  uVar5 = 0;
  uVar4 = uVar2 & 0xffff;
  if (uVar4 != 0) {
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
      uVar2 = ref_faultEnableStatus2((int)sVar1,0x20);
      uVar2 = uVar2 & 0xff;
      if (uVar2 == 0) {
        uVar2 = FUN_00061b28((int)sVar1);
      }
      uVar5 = uVar5 + 1;
    } while ((uVar5 & 0xffff) < uVar4);
  }
  return uVar2;
}


