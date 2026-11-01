/* ROM address: 0x000605c4; body bytes: 242; decompiled */

uint FUN_000605c4(uint param_1,undefined4 param_2,short param_3)

{
  bool bVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  
  sVar2 = DAT_ffffd3f0;
  iVar6 = (int)*(short *)(&DAT_0007daea + (param_1 & 0xffff) * 2);
  if ((DAT_ffffd201 == '\x01') || (DAT_ffffd994 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_000606fe(param_1);
  }
  uVar4 = (uint)DAT_ffffd6c4;
  if (uVar4 == 1) {
    uVar4 = FUN_00060166(iVar6,(int)sVar2);
    uVar4 = uVar4 & 0xff;
    if (uVar4 == 0) {
      if (DAT_ffffd299 == '\0') {
        uVar4 = FUN_00060154(iVar6,2);
        uVar4 = uVar4 & 0xff;
        if ((uVar4 == 0) && (!bVar1)) {
          uVar4 = FUN_00060806(param_1,uVar3,(int)param_3);
          return uVar4;
        }
      }
      else {
        cVar5 = FUN_00060154(iVar6,4);
        if (cVar5 != '\0') {
          uVar4 = FUN_00060154(iVar6,8);
          if ((uVar4 & 0xff) != 0) {
            return uVar4 & 0xff;
          }
        }
        uVar4 = 0;
        if (DAT_ffffd296 == '\0') {
          uVar4 = FUN_00060970(param_1,uVar3,(int)param_3);
          return uVar4;
        }
      }
    }
  }
  return uVar4;
}


