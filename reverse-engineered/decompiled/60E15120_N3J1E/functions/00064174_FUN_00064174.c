/* ROM address: 0x00064174; body bytes: 192; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062a64 (192 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00064174(ushort *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 3);
  iVar3 = (uint)DAT_ffff8900._0_2_ * 0x10;
  if ((bVar1 == 0) || (0x3f < bVar1)) {
    if (bVar1 == 0xc0) {
      uVar2 = (uint)(byte)(&DAT_ffff87b8)[iVar3];
      if ((byte)(&DAT_0007e442)[*param_1] <= uVar2) {
        uVar2 = FUN_00062dd8(0xc1);
      }
    }
    else {
      uVar2 = 1;
      if ((bVar1 == 0xc1) &&
         (uVar2 = (uint)(byte)(&DAT_ffff87b9)[iVar3], (byte)(&DAT_0007e4ce)[*param_1] <= uVar2)) {
        FUN_00062dd8(0);
        uVar2 = FUN_0006310a(8);
        return uVar2;
      }
    }
  }
  else if ((0x4f < (byte)(&DAT_ffff87ba)[iVar3]) ||
          (uVar2 = (uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2], uVar2 == 0x11)) {
    FUN_00062dd8(0);
    uVar2 = FUN_0006310a(8);
    return uVar2;
  }
  return uVar2;
}


