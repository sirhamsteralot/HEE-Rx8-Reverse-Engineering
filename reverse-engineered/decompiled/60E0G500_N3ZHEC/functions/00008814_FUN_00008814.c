/* ROM address: 0x00008814; body bytes: 522; decompiled */

void FUN_00008814(uint param_1)

{
  ushort uVar1;
  short sVar2;
  int extraout_r2;
  int iVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_2c;
  undefined *puStack_28;
  
  FUN_00002054(&local_2c,0xe0);
  uVar6 = DAT_ffff9f9c >> 4;
  FUN_00002064(local_2c);
  iVar8 = (param_1 & 0xff) * 0x18;
  sVar2 = (short)uVar6;
  if (*(int *)(&DAT_ffffa008 + iVar8) < 0) {
    *(short *)(&DAT_ffffa014 + iVar8) = sVar2;
  }
  else {
    FUN_00002158(DAT_ffff9f84,0x1e0000);
    iVar3 = FUN_0000467a();
    uVar6 = (int)((uint)(extraout_r2 * iVar3) >> 8) >> 4;
    sVar5 = (short)uVar6;
    if (0x7fff < (uVar6 & 0xffff)) {
      sVar5 = 0x7fff;
    }
    *(short *)(&DAT_ffffa014 + iVar8) = sVar2 + sVar5;
  }
  *(undefined4 *)(&DAT_ffffa010 + iVar8) = *(undefined4 *)(&DAT_ffffa004 + iVar8);
  FUN_00002054(&local_2c,0xe0);
  uVar6 = param_1 & 0xff;
  uVar1 = DAT_fffff666;
  if ((*(ushort *)(&PTR_DAT_0000d7dc + uVar6 * 3) & uVar1) == 0) {
    iVar4 = (&DAT_ffffa094)[param_1 & 0xff];
    iVar3 = *(int *)(&DAT_ffffa010 + iVar8);
    sVar2 = DAT_fffff440;
    if (0x7fff < (ushort)(*(short *)(&DAT_ffffa014 + iVar8) - (sVar2 + 3))) {
      *(short *)(&DAT_ffffa014 + iVar8) = sVar2 + 3;
    }
    puStack_28 = &DAT_ffffa004 + iVar8;
    *(undefined2 *)(&PTR_DAT_0000d7d8)[(param_1 & 0xff) * 3] =
         *(undefined2 *)(&DAT_ffffa014 + iVar8);
    FUN_0000a8a4((&PTR_DAT_0000d7d4)[(param_1 & 0xff) * 3],iVar3 + iVar4 >> 4);
    puStack_28[0x12] = 0;
  }
  else {
    sVar2 = DAT_fffff440;
    if ((ushort)((*(short *)(&PTR_DAT_0000d7d4)[uVar6 * 3] + sVar2) -
                *(short *)(&DAT_ffffa014 + iVar8)) < 0x8000) {
      if ((&DAT_ffffa016)[iVar8] == '\x01') {
        iVar3 = (*(int *)(&DAT_ffffa010 + iVar8) >> 4) +
                (int)*(short *)(&PTR_DAT_0000d7d4)[uVar6 * 3];
      }
      else {
        uVar7 = *(int *)(&DAT_ffffa010 + iVar8) + (&DAT_ffffa094)[param_1 & 0xff] >> 4;
        sVar2 = DAT_fffff440;
        uVar6 = (int)*(short *)(&DAT_ffffa014 + iVar8) - (int)sVar2 & 0xffff;
        if (uVar6 < 0x8000) {
          iVar3 = FUN_00002460(uVar7);
        }
        else if ((int)(uVar7 & 0xffff) < (int)-uVar6) {
          iVar3 = 0;
        }
        else {
          iVar3 = uVar7 + ((int)*(short *)(&DAT_ffffa014 + iVar8) - (int)sVar2);
        }
      }
      FUN_0000a8a4((&PTR_DAT_0000d7d4)[(param_1 & 0xff) * 3],iVar3);
      DAT_fffff666 = *(undefined2 *)(&PTR_DAT_0000d7dc + (param_1 & 0xff) * 3);
      (&DAT_ffffa016)[iVar8] = 0;
    }
    else {
      DAT_fffff66a = ~*(ushort *)(&PTR_DAT_0000d7dc + uVar6 * 3);
      uVar1 = DAT_fffff66c;
      DAT_fffff66c = ~*(ushort *)(&PTR_DAT_0000d7dc + uVar6 * 3) & uVar1 |
                     *(ushort *)(&PTR_DAT_0000d7dc + uVar6 * 3);
      (&DAT_ffffa018)[iVar8] = 1;
    }
  }
  FUN_00002064(local_2c);
  return;
}


