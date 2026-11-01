/* ROM address: 0x00027d38; body bytes: 286; decompiled */

char FUN_00027d38(void)

{
  ushort uVar1;
  ushort uVar3;
  int iVar2;
  char cVar4;
  char cVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  float fVar9;
  
  uVar1 = DAT_ffffb734;
  iVar8 = (int)(short)DAT_ffffb734;
  uVar3 = DAT_ffffb6d0 & 1;
  fVar9 = DAT_ffffb5b8;
  iVar2 = FUN_00003fe8();
  uVar7 = iVar8 + iVar2 * -0x11;
  DAT_ffffb95c = FUN_000024c0(0x3f800000,0,uVar7);
  DAT_ffffb960 = (float)FUN_00002068(DAT_ffffb95c,&DAT_0006abbc);
  uVar7 = uVar7 & 0xffff;
  if (uVar7 == 0) {
    cVar4 = '\x01';
  }
  else {
    cVar4 = FUN_0003eaa4(&DAT_ffff8570 + (uint)(ushort)(uVar1 - 1) * 2 + (uint)uVar3 * 0x88,0);
  }
  if (uVar7 == 0x10) {
    cVar5 = '\x01';
  }
  else {
    cVar5 = FUN_0003eaa4(&DAT_ffff8570 + (uint)(ushort)(uVar1 + 1) * 2 + (uint)uVar3 * 0x88,0);
  }
  cVar6 = FUN_0003eaa4(&DAT_ffff8570 + (uint)uVar1 * 2 + (uint)uVar3 * 0x88,0);
  if ((cVar6 != '\x01') ||
     (((DAT_ffffb960 <= fVar9 || (cVar6 = cVar4, cVar4 != '\x01')) &&
      ((fVar9 < DAT_ffffb960 || (cVar6 = cVar5, cVar5 != '\x01')))))) {
    DAT_ffffb736 = 0;
  }
  else {
    DAT_ffffb736 = 1;
  }
  return cVar6;
}


