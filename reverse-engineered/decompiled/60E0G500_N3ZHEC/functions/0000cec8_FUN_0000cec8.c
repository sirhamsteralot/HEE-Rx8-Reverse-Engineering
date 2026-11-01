/* ROM address: 0x0000cec8; body bytes: 32; decompiled */

void FUN_0000cec8(char param_1,ushort param_2)

{
  short sVar1;
  
  if (param_1 == '\0') {
    sVar1 = -0x1bf6;
  }
  else {
    sVar1 = -0x19f6;
  }
  *(ushort *)(int)sVar1 = param_2 << 8 | param_2 >> 8;
  return;
}


