/* ROM address: 0x0000b99c; body bytes: 460; decompiled */

undefined4 FUN_0000b99c(int param_1,int param_2,byte param_3)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  uint local_40;
  int iStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  byte bStack_24;
  
  bStack_24 = param_3;
  FUN_0000a850();
  uVar3 = 0;
  while (uVar1 = DAT_fffff75e, (uVar1 & 0x1000) != 0) {
    FUN_0000239c(10);
    uVar3 = uVar3 + 1;
    if (0x5db < uVar3) {
      DAT_ffffa320 = 1;
      return 1;
    }
  }
  FUN_0000a850();
  DAT_ffffed1a = 0xf7;
  FUN_00002054(&uStack_28,0xe0);
  FUN_00004bbc(0xfffff72c,0x100,0);
  FUN_00002064(uStack_28);
  FUN_00002054(&uStack_2c,0xe0);
  FUN_00004bbc(0xfffff72c,0x80,0);
  FUN_00002064(uStack_2c);
  uVar3 = 0;
  do {
    uVar1 = DAT_ffffed1a;
    if ((uVar1 & 8) != 0) {
      DAT_ffffed1a = 0xf7;
      DAT_ffffa31e = 0;
      iStack_3c = param_2;
      iStack_38 = param_1;
      do {
        if (bStack_24 <= DAT_ffffa31e) {
          FUN_00002054(&uStack_30,0xe0);
          FUN_00004bbc(0xfffff72c,0x100,1);
          FUN_00002064(uStack_30);
          FUN_00002054(&uStack_34,0xe0);
          FUN_00004bbc(0xfffff72c,0x80);
          FUN_00002064(uStack_34);
          DAT_ffffa320 = 0;
          return 0;
        }
        DAT_ffffecf8 = 2;
        DAT_ffffecf0 = 0xfffff00d;
        DAT_ffffecf4 = iStack_3c;
        DAT_ffffecfc._2_2_ = 0x100;
        DAT_ffffecfc = (undefined *)0x40100;
        DAT_ffffece8 = 2;
        DAT_ffffece0 = iStack_38;
        DAT_ffffece4 = 0xfffff00b;
        DAT_ffffecec._2_2_ = 0x1000;
        DAT_ffffecec = &DAT_00031000;
        bVar2 = DAT_fffff00c;
        DAT_fffff00c = bVar2 & 0x87 | 0x80;
        bVar2 = DAT_fffff00a;
        DAT_fffff00a = bVar2 & 0xb | 0xf0;
        uVar1 = DAT_ffffecb0;
        DAT_ffffecb0 = uVar1 & 0xfff8 | 1;
        uVar3 = DAT_ffffecfc;
        DAT_ffffecfc = uVar3 & 0xfffffff9 | 1;
        uVar3 = DAT_ffffecec;
        DAT_ffffecec = uVar3 & 0xfffffff9 | 1;
        iStack_38 = iStack_38 + 2;
        iStack_3c = iStack_3c + 2;
        local_40 = 0;
        while (uVar1 = DAT_ffffed1a, (uVar1 & 8) == 0) {
          FUN_0000239c(10);
          local_40 = local_40 + 1;
          if (99 < local_40) {
            DAT_ffffa320 = 1;
            return 1;
          }
        }
        DAT_ffffed1a = 0xf7;
        DAT_ffffa31e = DAT_ffffa31e + 1;
      } while( true );
    }
    FUN_0000239c(10);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 100);
  DAT_ffffa320 = 1;
  return 1;
}


