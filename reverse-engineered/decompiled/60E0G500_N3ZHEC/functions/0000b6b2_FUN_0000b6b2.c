/* ROM address: 0x0000b6b2; body bytes: 386; decompiled */

void FUN_0000b6b2(void)

{
  ushort uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined4 local_2c;
  undefined4 auStack_28 [3];
  
  if (DAT_ffffa322 != '\0') {
    DAT_ffffa321 = 0;
    if (DAT_ffffa31e < (byte)(&DAT_ffffa31a)[DAT_ffffa31c]) {
      DAT_ffffecf8 = 2;
      DAT_ffffecf0 = 0xfffff00d;
      DAT_ffffecf4 = &DAT_ffffa2a2 + DAT_ffffa31e;
      DAT_ffffecfc._2_2_ = 0x100;
      DAT_ffffecfc = (undefined *)0x40100;
      DAT_ffffece8 = 2;
      DAT_ffffece0 = &DAT_ffffa22a + (uint)DAT_ffffa31e * 2 + (uint)DAT_ffffa31c * 0x3c;
      DAT_ffffece4 = 0xfffff00b;
      DAT_ffffecec._2_2_ = 0x1000;
      DAT_ffffecec = &DAT_00031000;
      bVar3 = DAT_fffff00c;
      DAT_fffff00c = bVar3 & 0x87 | 0x80;
      bVar3 = DAT_fffff00a;
      DAT_fffff00a = bVar3 & 0xb | 0xf0;
      uVar1 = DAT_ffffecb0;
      DAT_ffffecb0 = uVar1 & 0xfff8 | 1;
      uVar2 = DAT_ffffecfc;
      DAT_ffffecfc = uVar2 & 0xfffffff9 | 1;
      uVar2 = DAT_ffffecec;
      DAT_ffffecec = uVar2 & 0xfffffff9 | 1;
      DAT_ffffa31e = DAT_ffffa31e + 1;
    }
    else {
      FUN_00002054(auStack_28,0xe0);
      FUN_00004bbc(0xfffff72c,0x100,1);
      FUN_00002064(auStack_28[0]);
      FUN_00002054(&local_2c,0xe0);
      FUN_00004bbc(0xfffff72c,0x80);
      FUN_00002064(local_2c);
      DAT_ffffa322 = '\0';
      iVar4 = 0;
      for (iVar5 = 0; iVar5 < (int)(uint)DAT_ffffa31e; iVar5 = iVar5 + 1) {
        *(undefined2 *)((int)&DAT_ffffa2de + iVar4) = *(undefined2 *)((int)&DAT_ffffa2a2 + iVar4);
        iVar4 = iVar4 + 2;
      }
      if (DAT_ffffa228 == '\0') {
        DAT_ffffa228 = '\x01';
      }
      else {
        DAT_ffffa228 = '\x02';
      }
      DAT_ffffa320 = 0;
      DAT_ffffa31c = DAT_ffffa31c + 1;
      if (1 < DAT_ffffa31c) {
        DAT_ffffa31c = 0;
      }
      DAT_ffffa31f = DAT_ffffa31f + -1;
      if (DAT_ffffa31f != '\0') {
        FUN_0000239c(4);
        FUN_0000bccc();
      }
    }
  }
  return;
}


