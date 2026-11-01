/* ROM address: 0x00064006; body bytes: 48; decompiled */

void FUN_00064006(undefined4 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)DAT_ffff8d74;
  iVar3 = uVar2 * 0x34;
  uVar1 = (&DAT_ffff8930)[uVar2 * 0x1a];
  (&DAT_ffff8962)[iVar3] =
       (&DAT_ffff8962)[iVar3] +
       (((char)uVar1 + (char)((ushort)uVar1 >> 8)) - ((char)((uint)param_1 >> 8) + (char)param_1));
  (&DAT_ffff8930)[uVar2 * 0x1a] = (short)param_1;
  return;
}


