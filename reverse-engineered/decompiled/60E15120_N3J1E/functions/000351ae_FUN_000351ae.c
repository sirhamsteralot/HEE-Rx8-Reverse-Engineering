/* ROM address: 0x000351ae; body bytes: 120; decompiled */

uint FUN_000351ae(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffc21e;
  if (uVar1 == 0) {
    DAT_ffffc226 = 1;
    uVar1 = (uint)DAT_ffffc21c;
    if (uVar1 == 1) {
      DAT_ffffc21d = 5;
      uVar1 = ref_ImmoStateReadyToDriveEngineOff();
      return uVar1;
    }
  }
  else {
    if (uVar1 == 1) {
      DAT_ffffc20c = 500;
      DAT_ffffc226 = 0;
      uVar1 = FUN_00034e68();
      return uVar1;
    }
    DAT_ffffc21e = 5;
    if (DAT_ffffc214 != 0) {
      DAT_ffffc214 = DAT_ffffc214 + -1;
    }
    if (DAT_ffffc214 == 0) {
      DAT_ffffc226 = 1;
      uVar1 = (uint)DAT_ffffc21c;
      if (uVar1 == 1) {
        DAT_ffffc21d = 5;
        uVar1 = ref_ImmoStateReadyToDriveEngineOff();
        return uVar1;
      }
    }
  }
  return uVar1;
}


