/* ROM address: 0x00000210; body bytes: 70; decompiled */

undefined4 FUN_00000210(undefined4 param_1)

{
  ushort uVar1;
  
  uVar1 = DAT_ffffe40e;
  if ((uVar1 & 0x100) == 0) {
    return 0;
  }
  uVar1 = DAT_ffffe41a;
  if ((uVar1 & 0x100) != 0) {
    DAT_ffffe41a = 0x100;
    return 0xffffffff;
  }
  DAT_ffffe40e = 0x100;
  FUN_00000ace(8,0,param_1,&DAT_ffffe4b0);
  return 1;
}


