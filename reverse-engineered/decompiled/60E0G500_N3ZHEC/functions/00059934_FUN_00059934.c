/* ROM address: 0x00059934; body bytes: 88; decompiled */

undefined4 FUN_00059934(uint param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  byte *pbVar3;
  uint uVar4;
  byte local_c [2];
  ushort uStack_a;
  
  uVar1 = DAT_ffffd3f0;
  pbVar3 = local_c;
  do {
    FUN_000042b0();
    uVar4 = (uint)*pbVar3;
    if (uVar4 == (param_1 & 0xff)) break;
  } while (uVar4 != 0);
  if ((uVar4 == 0) || ((uVar1 & uStack_a) == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


