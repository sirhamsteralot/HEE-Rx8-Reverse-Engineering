/* ROM address: 0x000085e4; body bytes: 200; decompiled */

void FUN_000085e4(uint param_1)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined4 local_20;
  undefined **ppuStack_1c;
  
  iVar3 = (param_1 & 0xff) * 0x18;
  if ((&DAT_ffffa017)[iVar3] == '\0') {
    FUN_00002054(&local_20,0xe0);
    if ((&DAT_ffffa018)[iVar3] == '\x01') {
      ppuStack_1c = &PTR_DAT_0000d7d4 + (param_1 & 0xff) * 3;
      uVar2 = DAT_fffff66c;
      DAT_fffff66c = ~*(ushort *)(&PTR_DAT_0000d7dc + (param_1 & 0xff) * 3) & uVar2;
      (&DAT_ffffa018)[iVar3] = 0;
    }
    else {
      sVar1 = DAT_fffff440;
      *(short *)(&PTR_DAT_0000d7d8)[(param_1 & 0xff) * 3] = sVar1 + -1;
      uVar2 = DAT_fffff666;
      if ((*(ushort *)(&PTR_DAT_0000d7dc + (param_1 & 0xff) * 3) & uVar2) == 0) {
        FUN_0000a8a4((&PTR_DAT_0000d7d4)[(param_1 & 0xff) * 3],0);
      }
    }
    FUN_00002064(local_20);
  }
  (&DAT_ffffa017)[iVar3] = 0;
  return;
}


