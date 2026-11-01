/* ROM address: 0x00065e34; body bytes: 164; decompiled */

undefined4 FUN_00065e34(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  
  uVar2 = 1;
  cVar1 = FUN_00067f1c(param_1,&fStack_20);
  if (cVar1 == '\0') {
    fVar3 = (float)FUN_0006049c();
    fVar4 = (float)FUN_00060496();
    cVar1 = FUN_00060488();
    fVar4 = rx8_absolute_difference(fVar4,fStack_1c);
    fVar3 = rx8_absolute_difference(fVar3,fStack_20);
    if (fStack_18 < 71.0) {
      if (((cVar1 == '\0') && (fVar4 <= 0.2)) && (fVar3 <= 375.0)) {
        uVar2 = 0;
      }
    }
    else if (((cVar1 == '\x01') && (fVar4 <= 0.2)) && (fVar3 <= 375.0)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}


