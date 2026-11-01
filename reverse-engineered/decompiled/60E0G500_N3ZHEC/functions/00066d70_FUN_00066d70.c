/* ROM address: 0x00066d70; body bytes: 84; decompiled */

uint FUN_00066d70(char param_1)

{
  ushort uVar1;
  uint uVar2;
  char local_d [5];
  
  local_d[0] = param_1;
  uVar2 = FUN_00056220((int)param_1,&DAT_ffffd942);
  if ((uVar2 & 0xff) != 0) {
    FUN_000688c8(9,local_d,1);
    uVar1 = (ushort)uVar2;
    DAT_ffffd940 = DAT_ffffd940 + 1;
    uVar2 = FUN_000688c8(9,&DAT_ffffd942);
    DAT_ffffd940 = DAT_ffffd940 + (uVar1 & 0xff);
  }
  return uVar2;
}


