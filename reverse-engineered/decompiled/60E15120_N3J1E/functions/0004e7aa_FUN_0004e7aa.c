/* ROM address: 0x0004e7aa; body bytes: 48; decompiled */

bool FUN_0004e7aa(void)

{
  ushort uVar1;
  
  uVar1 = PFDR_W;
  DAT_ffffcfb8 = (uVar1 & 1) != 0;
  return DAT_ffffcfb8;
}


