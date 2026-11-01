/* ROM address: 0x0004af18; body bytes: 138; decompiled */

void FUN_0004af18(void)

{
  undefined4 uVar1;
  float fVar2;
  
  if (DAT_ffffd201 == '\0') {
    fVar2 = DAT_ffffcdb8;
    uVar1 = FUN_000024c0(0x42000000,0,(int)DAT_ffffcdc8);
    DAT_ffffcde0 = (float)FUN_00002068(uVar1,&DAT_0006be38);
    DAT_ffffcde4 = (float)FUN_00002068(uVar1,&DAT_0006be44);
    if (fVar2 < DAT_ffffcde0) {
      DAT_ffffcdc0 = '\x01';
    }
    if (DAT_ffffcde4 <= fVar2) {
      DAT_ffffcdc1 = '\x01';
    }
    if ((DAT_ffffcdc0 == '\x01') && (DAT_ffffcdc1 == '\x01')) {
      DAT_ffffcdc2 = 1;
    }
  }
  else {
    DAT_ffffcdc0 = '\0';
    DAT_ffffcdc1 = '\0';
    DAT_ffffcdc2 = 0;
  }
  return;
}


