/* ROM address: 0x00063552; body bytes: 42; decompiled */

void FUN_00063552(undefined4 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)DAT_ffff8928;
  iVar3 = uVar2 * 0x10;
  uVar1 = (&DAT_ffff87d8)[uVar2 * 8];
  (&DAT_ffff87e6)[iVar3] =
       (&DAT_ffff87e6)[iVar3] +
       (((char)uVar1 + (char)((ushort)uVar1 >> 8)) - ((char)((uint)param_1 >> 8) + (char)param_1));
  (&DAT_ffff87d8)[uVar2 * 8] = (short)param_1;
  return;
}


