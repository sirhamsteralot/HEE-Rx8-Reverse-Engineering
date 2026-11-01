/* ROM address: 0x00008b4c; body bytes: 440; decompiled */

void FUN_00008b4c(uint param_1,int param_2)

{
  short sVar1;
  ushort uVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined **ppuVar7;
  undefined4 local_28;
  undefined **ppuStack_24;
  
  FUN_00002054(&local_28,0xe0);
  uVar6 = param_1 & 0xff;
  iVar5 = (param_1 & 0xff) * 0x18;
  ppuVar7 = &PTR_DAT_0000d7d4 + uVar6 * 3;
  if ((&DAT_ffffa018)[iVar5] == '\x01') {
    uVar6 = (param_2 >> 4) + (int)*(short *)*ppuVar7;
    sVar1 = DAT_fffff440;
    if ((((int)sVar1 + uVar6) - (int)*(short *)(&DAT_ffffa014 + iVar5) & 0xffff) < 0x8000) {
      uVar6 = uVar6 + (*(int *)(&DAT_ffffa010 + iVar5) >> 4);
      ppuStack_24 = &PTR_DAT_0000d7d4 + (param_1 & 0xff) * 3;
      uVar2 = DAT_fffff66c;
      DAT_fffff66c = ~*(ushort *)(&PTR_DAT_0000d7dc + (param_1 & 0xff) * 3) & uVar2;
      (&DAT_ffffa018)[iVar5] = 0;
      (&DAT_ffffa016)[iVar5] = 0;
    }
    if ((uVar6 & 0xffff) != 0) {
      param_1 = param_1 & 0xff;
      FUN_0000a8a4((&PTR_DAT_0000d7d4)[param_1 * 3]);
      DAT_fffff666 = *(undefined2 *)(&PTR_DAT_0000d7dc + param_1 * 3);
      DAT_fffff66a = ~*(ushort *)(&PTR_DAT_0000d7dc + param_1 * 3);
    }
  }
  else if (*(short *)*ppuVar7 == 0) {
    FUN_0000a8a4(*ppuVar7,param_2 + (&DAT_ffffa094)[param_1 & 0xff] >> 4);
    DAT_fffff666 = *(undefined2 *)(&PTR_DAT_0000d7dc + uVar6 * 3);
    (&DAT_ffffa016)[iVar5] = 1;
  }
  else {
    uVar2 = DAT_fffff666;
    if ((*(ushort *)(&PTR_DAT_0000d7dc + uVar6 * 3) & uVar2) == 0) {
      iVar4 = param_2 + (&DAT_ffffa094)[param_1 & 0xff] >> 4;
      sVar1 = DAT_fffff440;
      if (0x7fff < ((sVar1 + iVar4) - (int)*(short *)(&DAT_ffffa014 + iVar5) & 0xffffU)) {
        DAT_fffff66a = ~*(ushort *)(&PTR_DAT_0000d7dc + uVar6 * 3);
        FUN_0000a8a4(*ppuVar7);
        DAT_fffff666 = *(undefined2 *)(&PTR_DAT_0000d7dc + uVar6 * 3);
        uVar2 = DAT_fffff66c;
        DAT_fffff66c = ~*(ushort *)(&PTR_DAT_0000d7dc + uVar6 * 3) & uVar2 |
                       *(ushort *)(&PTR_DAT_0000d7dc + uVar6 * 3);
        (&DAT_ffffa018)[iVar5] = 1;
        (&DAT_ffffa016)[iVar5] = 1;
        goto LAB_00008d0e;
      }
      psVar3 = (short *)*ppuVar7;
      iVar4 = iVar4 + (*(int *)(&DAT_ffffa010 + iVar5) >> 4);
    }
    else {
      psVar3 = (short *)*ppuVar7;
      iVar4 = (int)*psVar3 + (param_2 >> 4);
    }
    FUN_0000a8a4(psVar3,iVar4);
    DAT_fffff666 = *(undefined2 *)(&PTR_DAT_0000d7dc + uVar6 * 3);
  }
LAB_00008d0e:
  FUN_00002064(local_28);
  return;
}


