/* ROM address: 0x00064918; body bytes: 192; decompiled */

uint FUN_00064918(ushort *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 3);
  iVar3 = (uint)DAT_ffff8928 * 0x10;
  if ((bVar1 == 0) || (0x3f < bVar1)) {
    if (bVar1 == 0xc0) {
      uVar2 = (uint)(byte)(&DAT_ffff87e0)[iVar3];
      if ((byte)(&DAT_0007dfea)[*param_1] <= uVar2) {
        uVar2 = FUN_0006357c(0xc1);
      }
    }
    else {
      uVar2 = 1;
      if ((bVar1 == 0xc1) &&
         (uVar2 = (uint)(byte)(&DAT_ffff87e1)[iVar3], (byte)(&DAT_0007e076)[*param_1] <= uVar2)) {
        FUN_0006357c(0);
        uVar2 = FUN_000638ae(8);
        return uVar2;
      }
    }
  }
  else if ((0x4f < (byte)(&DAT_ffff87e2)[iVar3]) ||
          (uVar2 = (uint)(byte)(&DAT_ffff8d7c)[(uint)*param_1 * 2], uVar2 == 0x11)) {
    FUN_0006357c(0);
    uVar2 = FUN_000638ae(8);
    return uVar2;
  }
  return uVar2;
}


