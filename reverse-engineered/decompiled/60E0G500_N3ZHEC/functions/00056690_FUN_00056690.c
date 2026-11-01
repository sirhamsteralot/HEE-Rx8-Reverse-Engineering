/* ROM address: 0x00056690; body bytes: 98; decompiled */

bool FUN_00056690(uint param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  uint uVar2;
  byte local_14 [8];
  
  pbVar1 = local_14;
  do {
    FUN_000042b0();
    uVar2 = (uint)*pbVar1;
    if (((uVar2 == (param_1 & 0xff)) && (pbVar1[1] == param_2)) && (pbVar1[2] == param_3)) break;
  } while (uVar2 < 5);
  return 4 < uVar2;
}


