/* ROM address: 0x00066124; body bytes: 90; decompiled */

uint FUN_00066124(char param_1)

{
  uint uVar1;
  short sVar2;
  undefined1 auStack_14 [7];
  char local_d [5];
  
  local_d[0] = param_1;
  uVar1 = thunk_FUN_00055534((int)param_1);
  if ((uVar1 & 0xff) != 0) {
    FUN_000688c8(1,local_d);
    DAT_ffffd852 = DAT_ffffd852 + 1;
    sVar2 = (short)(uVar1 & 0xff);
    FUN_000688c8(1,auStack_14,uVar1 & 0xff);
    uVar1 = (uint)sVar2;
    DAT_ffffd852 = DAT_ffffd852 + sVar2;
  }
  return uVar1;
}


