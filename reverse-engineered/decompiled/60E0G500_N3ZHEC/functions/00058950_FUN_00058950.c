/* ROM address: 0x00058950; body bytes: 54; decompiled */

undefined4 FUN_00058950(short param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_00060166((int)param_1,(int)DAT_ffffd3f0);
  if ((cVar1 == '\0') && (cVar1 = FUN_00060154((int)param_1,2), cVar1 == '\0')) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


