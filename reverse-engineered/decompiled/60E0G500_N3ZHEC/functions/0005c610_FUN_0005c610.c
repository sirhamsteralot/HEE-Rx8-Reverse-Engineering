/* ROM address: 0x0005c610; body bytes: 228; decompiled */

uint FUN_0005c610(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  byte bVar5;
  byte bVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  undefined1 local_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  char cStack_21;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  
  uVar7 = FUN_00003920(0x10);
  bVar6 = DAT_ffffd356;
  bVar5 = DAT_ffffd355;
  uVar4 = DAT_ffffd350;
  cVar1 = *(&PTR_DAT_0005fed8)[(uint)DAT_ffffd356 * 4];
  uVar2 = (&DAT_ffffd371)[(uint)DAT_ffffd356 * 2];
  uVar3 = (&DAT_ffffd372)[(uint)DAT_ffffd356 * 2];
  FUN_00003934(uVar7);
  uVar8 = (uint)bVar5;
  if (uVar8 == 1) {
    DAT_ffffd350 = 0;
    DAT_ffffd355 = 0;
    local_24 = 0x6f;
    uStack_23 = (undefined1)((ushort)uVar4 >> 8);
    uStack_22 = (undefined1)uVar4;
    if ((cVar1 == '\x05') || (cVar1 == '\a')) {
      iVar9 = (byte)(&DAT_0005fed7)[(uint)bVar6 * 0x10] + 4;
    }
    else {
      iVar9 = 4;
    }
    cStack_21 = cVar1;
    uStack_20 = uVar2;
    uStack_1f = uVar3;
    FUN_000688c8(0x2f,&local_24,iVar9);
    uVar8 = FUN_000550ca(0x2f,iVar9);
  }
  else if (uVar8 == 2) {
    DAT_ffffd350 = 0;
    DAT_ffffd355 = 0;
    uVar7 = FUN_00055112(0x2f,0x22);
    uVar8 = FUN_000550ca(0x2f,uVar7);
  }
  return uVar8;
}


