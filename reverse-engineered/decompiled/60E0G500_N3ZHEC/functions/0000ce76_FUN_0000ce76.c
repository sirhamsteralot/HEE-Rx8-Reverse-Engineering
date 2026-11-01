/* ROM address: 0x0000ce76; body bytes: 50; decompiled */

ushort FUN_0000ce76(char param_1)

{
  short sVar1;
  ushort uVar2;
  
  if (param_1 == '\0') {
    uVar2 = DAT_ffffe414;
    sVar1 = -0x1bf6;
  }
  else {
    uVar2 = DAT_ffffe614;
    sVar1 = -0x19f6;
  }
  return (~uVar2 & *(ushort *)(int)sVar1) << 8 | (~uVar2 & *(ushort *)(int)sVar1) >> 8;
}


