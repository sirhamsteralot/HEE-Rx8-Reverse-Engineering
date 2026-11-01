/* ROM address: 0x0002885a; body bytes: 392; decompiled */

undefined1 * FUN_0002885a(void)

{
  bool bVar1;
  char cVar2;
  undefined1 *puVar3;
  ushort uVar4;
  short sVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 local_30;
  undefined1 local_2f;
  
  cVar2 = DAT_ffffad90;
  if ((DAT_ffffba8b == '\0') && (DAT_ffffad90 == '\x01')) {
    DAT_ffffba8c = '\x01';
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (((DAT_ffffaae0 == '\x01') && (DAT_ffffa41c == '\x01')) && (DAT_ffffba8c == '\x01')) {
    if ((DAT_ffffba7e < 1000) && (bVar1)) {
      DAT_ffffba89 = FUN_00002478((int)DAT_ffffba89,1);
      if (DAT_ffffba89 == '\x14') {
        DAT_ffffba8e = 1;
        FUN_0003ebc0(&DAT_ffff8684,0);
        uVar8 = 0;
        uVar6 = 0xc27c0000;
        uVar4 = 0;
        sVar5 = 0;
        uVar7 = 0x3f000000;
        do {
          local_30 = FUN_000024d0(uVar8,uVar7,uVar6);
          local_2f = 0;
          FUN_00038e8c((int)(short)(sVar5 + 0x20),&local_30,2);
          uVar4 = uVar4 + 1;
          sVar5 = sVar5 + 2;
        } while (uVar4 < 0x22);
        DAT_ffffba8a = FUN_000388c4(0x20,0x44,3);
      }
    }
    DAT_ffffba7e = FUN_00002460((int)(short)DAT_ffffba7e,1);
  }
  else {
    DAT_ffffba8c = '\0';
    DAT_ffffba7e = 0;
    DAT_ffffba89 = '\0';
  }
  puVar3 = (undefined1 *)(uint)DAT_ffffba8e;
  if (puVar3 == (undefined1 *)0x1) {
    if (DAT_ffffba8a == '\x01') {
      puVar3 = (undefined1 *)FUN_000388c4(0x20,0x44,3);
      DAT_ffffba8a = (char)puVar3;
    }
    else if (DAT_ffffc2fd == '\x01') {
      DAT_ffffba8e = 0;
      puVar3 = (undefined1 *)0x1;
    }
    else {
      puVar3 = (undefined1 *)(uint)DAT_ffffc2fa;
      if (puVar3 == (undefined1 *)0x1) {
        DAT_ffffba8e = 0;
        puVar3 = &DAT_ffffb738;
        DAT_ffffb738 = 1;
        DAT_ffffba80 = -0x80;
      }
    }
  }
  if (DAT_ffffba80 == '\0') {
    DAT_ffffb738 = 0;
  }
  else {
    DAT_ffffba80 = DAT_ffffba80 + -1;
  }
  DAT_ffffba8b = cVar2;
  return puVar3;
}


