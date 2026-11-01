/* ROM address: 0x000276f8; body bytes: 90; decompiled */

undefined4 FUN_000276f8(char param_1,char param_2,ushort *param_3,ushort *param_4)

{
  undefined4 uVar1;
  
  if ((param_1 == '\x01') || (param_2 == '\x01')) {
    uVar1 = 1;
    if (*param_3 < 0xff) {
      uVar1 = FUN_00002460((int)(short)*param_3,1);
      *param_3 = (ushort)uVar1;
    }
    if (*param_4 < 0xff) {
      uVar1 = FUN_00002460((int)(short)*param_4,1);
      *param_4 = (ushort)uVar1;
    }
    DAT_ffffb704 = 1;
  }
  else {
    uVar1 = 0;
    DAT_ffffb704 = 0;
  }
  return uVar1;
}


