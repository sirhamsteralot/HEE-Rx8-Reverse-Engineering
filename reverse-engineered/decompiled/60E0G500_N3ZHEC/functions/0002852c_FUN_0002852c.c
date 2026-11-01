/* ROM address: 0x0002852c; body bytes: 342; decompiled */

uint FUN_0002852c(void)

{
  bool bVar1;
  char cVar3;
  uint uVar2;
  ushort uVar4;
  undefined *puVar5;
  int iVar6;
  undefined *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined1 local_30;
  undefined1 local_2f;
  
  if (DAT_ffffaae0 == '\x01') {
    DAT_ffffb737 = 1;
    DAT_ffffba82 = 0;
    DAT_ffffba8d = 0;
    return 1;
  }
  if (DAT_ffffb737 != 1) {
    return (uint)DAT_ffffb737;
  }
  bVar1 = true;
  cVar3 = FUN_0003eaa4(&DAT_ffff8682,0);
  if (cVar3 != '\x01') {
    if (DAT_ffffba8d != '\x01') {
      DAT_ffffba8d = '\x01';
      FUN_0003ebc0(&DAT_ffff8680,1);
      uVar4 = 0;
      puVar5 = &DAT_ffff8570;
      uVar11 = 0;
      puVar7 = &DAT_ffff8130;
      iVar6 = 0;
      uVar9 = 0xc27c0000;
      uVar10 = 0x3f000000;
      do {
        uVar8 = FUN_0003eb72(uVar11,puVar7);
        local_30 = FUN_000024d0(uVar8,uVar10,uVar9);
        local_2f = FUN_0003eaa4(puVar5,0);
        FUN_00038e8c(iVar6 + 0x20,&local_30,2);
        uVar4 = uVar4 + 1;
        iVar6 = iVar6 + 2;
        puVar5 = puVar5 + 2;
        puVar7 = puVar7 + 8;
      } while (uVar4 < 0x22);
      uVar2 = FUN_000388c4(0x20,0x44,3);
      DAT_ffffba8a = (char)uVar2;
      goto LAB_00028668;
    }
    if (DAT_ffffba8a == '\x01') {
      uVar2 = FUN_000388c4(0x20,0x44,3);
      DAT_ffffba8a = (char)uVar2;
      goto LAB_00028668;
    }
    if (DAT_ffffc2fd != '\x01') {
      uVar2 = (uint)DAT_ffffc2fa;
      if (uVar2 == 1) {
        uVar2 = FUN_0003ebc0(&DAT_ffff8680,0);
        bVar1 = false;
      }
      goto LAB_00028668;
    }
  }
  uVar2 = 1;
  bVar1 = false;
LAB_00028668:
  if ((bVar1) && (DAT_ffffba82 < 0x4e2)) {
    DAT_ffffba82 = DAT_ffffba82 + 1;
  }
  else {
    DAT_ffffb737 = 0;
  }
  return uVar2;
}


