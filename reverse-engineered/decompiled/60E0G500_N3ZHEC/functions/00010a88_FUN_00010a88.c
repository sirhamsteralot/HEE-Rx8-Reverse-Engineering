/* ROM address: 0x00010a88; body bytes: 140; decompiled */

uint FUN_00010a88(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  
  uVar1 = FUN_00010f6e();
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 1) {
    uVar2 = FUN_00010ea8();
    uVar1 = uVar2;
    for (puVar3 = &DAT_ffffa578; puVar3 < &DAT_ffffa5d0; puVar3 = puVar3 + 0x2c) {
      uVar1 = FUN_000107f0(param_1,*(undefined4 *)(puVar3 + 4));
      if ((-1 < (int)uVar1) && ((int)uVar1 < 0x1e0000)) {
        for (pbVar4 = puVar3 + 0xc; pbVar4 < puVar3 + 0x2c; pbVar4 = pbVar4 + 0x10) {
          uVar1 = (uint)*pbVar4 * 2;
          if (((uint)*(ushort *)((int)&PTR_DAT_0004ea80 + uVar1) & uVar2 & 0xffff) == 0) {
            uVar1 = FUN_00008d30((int)(char)*pbVar4);
          }
        }
      }
    }
  }
  return uVar1;
}


