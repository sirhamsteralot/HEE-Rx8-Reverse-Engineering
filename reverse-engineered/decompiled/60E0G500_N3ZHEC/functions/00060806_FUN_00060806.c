/* ROM address: 0x00060806; body bytes: 272; decompiled */

uint FUN_00060806(uint param_1,uint param_2,short param_3)

{
  byte bVar1;
  char cVar3;
  uint uVar2;
  int iVar4;
  uint uVar5;
  
  iVar4 = (int)(short)*(ushort *)(&DAT_0007daea + (param_1 & 0xffff) * 2);
  uVar5 = (uint)*(ushort *)(&DAT_0007daea + (param_1 & 0xffff) * 2);
  bVar1 = (&DAT_0007ded2)[uVar5];
  param_2 = param_2 & 0xff;
  if (param_2 == 2) {
    cVar3 = FUN_00060154(iVar4,0x10);
    if (cVar3 == '\0') {
      cVar3 = FUN_00061fa4(iVar4);
      param_2 = 0;
      if (cVar3 != '\0') {
        FUN_000622cc(iVar4);
        FUN_00060a6c(iVar4,0);
        (&DAT_ffffd520)[uVar5] = 2;
        param_2 = uVar5;
      }
    }
    else {
      param_2 = (uint)(byte)(&DAT_ffffd520)[uVar5];
      if ((byte)(&DAT_ffffd520)[uVar5] != 2) {
        FUN_00060934(param_1,0x10,0);
        (&DAT_ffffd520)[uVar5] = 2;
        param_2 = uVar5;
      }
    }
  }
  else if (param_2 == 4) {
    param_2 = (uint)(byte)(&DAT_ffffd520)[uVar5];
    if (((byte)(&DAT_ffffd520)[uVar5] != 4) &&
       (((bVar1 == 3 || (bVar1 == 1)) || (param_2 = (uint)bVar1, bVar1 == 2)))) {
      FUN_00060934(param_1,0x11,0);
      (&DAT_ffffd520)[uVar5] = 4;
      param_2 = uVar5;
    }
  }
  else if ((param_2 == 1) &&
          ((((&DAT_ffffd520)[uVar5] != '\x01' || (bVar1 == 1)) ||
           (param_2 = (uint)bVar1, bVar1 == 2)))) {
    uVar2 = FUN_0006030c(iVar4);
    param_2 = uVar2 & 0xff;
    if ((uVar2 & 0xff) == 0) {
      FUN_00060934(param_1,0x20,(int)param_3);
      (&DAT_ffffd520)[uVar5] = 1;
      param_2 = uVar5;
    }
  }
  return param_2;
}


