/* ROM address: 0x00001150; body bytes: 50; decompiled */

void FUN_00001150(undefined4 param_1)

{
  ushort uVar1;
  
  do {
    uVar1 = DAT_ffffe406;
  } while ((uVar1 & 0x80) != 0);
  DAT_ffffe40a = 0x80;
  FUN_00001fbc(8,0,param_1,&DAT_ffffe528);
  DAT_ffffe406 = 0x80;
  return;
}


