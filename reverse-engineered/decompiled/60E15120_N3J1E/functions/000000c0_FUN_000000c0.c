/* ROM address: 0x000000c0; body bytes: 24; decompiled */

uint FUN_000000c0(int param_1)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 1) & 7) == 0) {
    uVar1 = FUN_00000338(0xc0,6,0xfe4);
    return uVar1;
  }
  return (uint)*(byte *)(param_1 + 1);
}


