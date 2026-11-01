/* ROM address: 0x00009ac4; body bytes: 32; decompiled */

bool FUN_00009ac4(undefined4 param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)FUN_0000cefe(param_1,&DAT_ffffe401);
  return (*pbVar1 & 1) != 0;
}


