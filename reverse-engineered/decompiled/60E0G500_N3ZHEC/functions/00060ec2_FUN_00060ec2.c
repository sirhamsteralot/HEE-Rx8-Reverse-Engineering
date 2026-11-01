/* ROM address: 0x00060ec2; body bytes: 184; decompiled */

int FUN_00060ec2(undefined4 param_1)

{
  char cVar1;
  int unaff_r9;
  ushort uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  ushort auStack_2c [2];
  ushort uStack_28;
  char cStack_25;
  byte bStack_24;
  
  uVar2 = 0xffff;
  bVar3 = 0xff;
  iVar4 = 1;
  iVar5 = 1;
  do {
    cVar1 = FUN_00064304(iVar5,auStack_2c);
    if (cVar1 != '\x01') break;
    if (((&DAT_0007e2ac)[auStack_2c[0]] == '\x01') && (cStack_25 == -0x40)) {
      if (bStack_24 < bVar3) {
        iVar4 = 0;
        unaff_r9 = iVar5;
        bVar3 = bStack_24;
        uVar2 = uStack_28;
      }
      else if ((bVar3 == bStack_24) && (uStack_28 < uVar2)) {
        iVar4 = 0;
        unaff_r9 = iVar5;
        bVar3 = bStack_24;
        uVar2 = uStack_28;
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x15);
  if (iVar4 == 0) {
    FUN_000643c0(unaff_r9,param_1);
  }
  return iVar4;
}


