/* ROM address: 0x00060c66; body bytes: 36; decompiled */

uint FUN_00060c66(char param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(short)DAT_ffffd3f0;
  if (param_1 == '\0') {
    uVar1 = (uint)(DAT_ffffd3f0 >> 8);
  }
  else if (param_1 != '\x01') {
    uVar1 = 0;
  }
  return uVar1;
}


