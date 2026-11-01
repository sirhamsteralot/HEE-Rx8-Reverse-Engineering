/* ROM address: 0x0005b8de; body bytes: 386; decompiled */

void FUN_0005b8de(void)

{
  short sVar4;
  uint uVar1;
  char cVar8;
  ushort uVar5;
  ushort uVar6;
  undefined4 uVar2;
  short sVar7;
  int iVar3;
  uint uVar9;
  uint uVar10;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 uStack_4a;
  undefined1 auStack_48 [44];
  
  if (DAT_ffffd320 == '\0') {
    return;
  }
  sVar4 = FUN_0006012e((int)DAT_ffffd322);
  if (sVar4 == 3) {
    uVar1 = FUN_00060108((int)DAT_ffffd322);
  }
  else {
    uVar1 = 0;
  }
  uVar9 = 0x8c;
  uVar10 = uVar9;
  if ((uVar1 & 0xffff) == 0x8c) goto LAB_0005ba0a;
  if ((uVar1 & 0xffff) != 0) {
    cVar8 = FUN_00061fa4(uVar1);
    uVar10 = uVar1;
    if ((cVar8 != -0x40) && (cVar8 != -0x3f)) {
      uVar10 = uVar9;
    }
    goto LAB_0005ba0a;
  }
  cVar8 = FUN_00061fa4(0);
  if (((cVar8 == -0x40) || (cVar8 == -0x3f)) || (cVar8 == 'p')) {
    uVar10 = 0;
  }
  cVar8 = FUN_00061fa4(1);
  if (((cVar8 == -0x40) || (cVar8 == -0x3f)) || (cVar8 == 'p')) {
    if (uVar10 != 0x8c) {
      uVar5 = FUN_000639ce(1);
      uVar6 = FUN_000639ce(0);
      if (uVar6 <= uVar5) goto LAB_0005b9b8;
    }
    uVar10 = 1;
  }
LAB_0005b9b8:
  if (uVar10 != 0x8c) {
    uVar2 = FUN_00068360(0);
    sVar7 = FUN_00060070(uVar2);
    if (sVar4 != sVar7) {
      uVar10 = uVar9;
    }
  }
LAB_0005ba0a:
  if (((uVar10 & 0xffff) == 0x8c) || (cVar8 = FUN_0006228a(uVar10,auStack_48), cVar8 != '\0')) {
    iVar3 = FUN_00055112(0x12,0x31);
  }
  else {
    local_4c = 0x52;
    local_4b = 0;
    FUN_000688c8(0x12,&local_4c,2);
    iVar3 = FUN_0005bade(auStack_48);
    local_4c = 4;
    local_4b = (undefined1)((ushort)DAT_ffffd322 >> 8);
    uStack_4a = (undefined1)DAT_ffffd322;
    FUN_000688c8(0x12,&local_4c,3);
    iVar3 = iVar3 + 5;
  }
  FUN_000550ca(0x12,iVar3);
  FUN_0005b8d2();
  return;
}


