/* ROM address: 0x0005de7c; body bytes: 138; decompiled */

undefined4 FUN_0005de7c(byte param_1,ushort param_2)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar4 = 0;
  uVar5 = 0xff;
  iVar1 = (uint)param_1 * 0x10;
  if (param_1 == 9) {
    if (param_2 != 0) {
      uVar4 = uVar5;
    }
  }
  else {
    uVar3 = (uint)(byte)(&DAT_0005fed6)[iVar1];
    if (uVar3 == 0) {
      if ((param_2 < *(ushort *)(&DAT_0005fed0 + iVar1)) ||
         (*(ushort *)(&DAT_0005fed2 + iVar1) < param_2)) {
        uVar4 = uVar5;
      }
    }
    else {
      cVar2 = FUN_0000467a();
      if (uVar3 == 1) {
        if ((cVar2 != '\x01') && (cVar2 != '\0')) {
          uVar4 = uVar5;
        }
      }
      else if ((uVar3 == 2) && (cVar2 != '\0')) {
        uVar4 = uVar5;
      }
    }
  }
  return uVar4;
}


