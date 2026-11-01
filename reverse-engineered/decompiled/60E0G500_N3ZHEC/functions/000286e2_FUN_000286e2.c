/* ROM address: 0x000286e2; body bytes: 314; decompiled */

void FUN_000286e2(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  ushort uStack_38;
  char local_34;
  char local_33;
  
  if ((((DAT_ffffba8f == '\0') && (DAT_ffffc724 == '\x01')) ||
      ((DAT_ffffba8e == '\0' && (cVar1 = FUN_0003eaa4(&DAT_ffff8684,0), cVar1 == '\0')))) &&
     (cVar1 = FUN_00038cc0(0x20,0x44), cVar1 == '\0')) {
    FUN_0003ebc0(&DAT_ffff8682,1);
    fVar7 = 1.0;
    iVar4 = 0;
    uStack_38 = 0;
    iVar5 = 0;
    iVar3 = 0;
    uVar8 = 0xc27c0000;
    uVar9 = 0x3f000000;
    do {
      cVar1 = FUN_00038ed8(iVar3 + 0x20,&local_34,2);
      if (cVar1 == '\0') {
        fVar6 = (float)FUN_00002500(uVar9,uVar8,(int)local_34);
        if (local_33 == -1) {
          iVar2 = 0;
        }
        else {
          iVar2 = (int)local_33;
        }
        FUN_0003ec20(fVar6,&DAT_ffff8130 + iVar5);
        FUN_0003ebc0(&DAT_ffff8570 + iVar4,iVar2);
        FUN_0003ec20(-(fVar6 * fVar7),&DAT_ffff8350 + iVar5);
        FUN_0003ebc0(&DAT_ffff85f8 + iVar4,iVar2);
      }
      iVar4 = iVar4 + 2;
      uStack_38 = uStack_38 + 1;
      iVar5 = iVar5 + 8;
      iVar3 = iVar3 + 2;
    } while (uStack_38 < 0x22);
    FUN_0003ebc0(&DAT_ffff8682,0);
    FUN_0003ebc0(&DAT_ffff8684,1);
  }
  DAT_ffffba8f = 1;
  return;
}


