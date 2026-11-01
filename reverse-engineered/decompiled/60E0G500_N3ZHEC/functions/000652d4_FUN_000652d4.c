/* ROM address: 0x000652d4; body bytes: 292; decompiled */

uint FUN_000652d4(ushort param_1,char param_2,char param_3)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  
  cVar1 = (&DAT_ffff8d7c)[(uint)param_1 * 2];
  uVar3 = (uint)param_2;
  cVar2 = FUN_00065d40((int)param_2);
  if ((cVar2 == '\0') || (cVar2 == 'P')) {
    if (DAT_ffffd7ee != '\x01') {
      if ((param_3 != '\0') && (param_3 != '\x01')) {
        return uVar3;
      }
      FUN_00065ab8();
      FUN_00065a58();
      return 1;
    }
    FUN_00065ab8();
  }
  else {
    if ((cVar2 == '`') || (cVar2 == 'p')) {
      if ((DAT_ffffd7ef == '\0') &&
         (((cVar2 = FUN_00065e34((int)(short)param_1), DAT_ffff8ea0._0_1_ == ' ' || (cVar2 == '\0'))
          || (DAT_ffffd7ee == '\x01')))) {
        uVar3 = 0xc0;
      }
      if (cVar1 == ' ') {
        return uVar3;
      }
      if ((uVar3 & 0xff) == 0xc0) {
        return uVar3;
      }
      if ((param_3 != '\0') && (param_3 != '\x01')) {
        return uVar3;
      }
      FUN_00065a58();
      return uVar3;
    }
    if (cVar2 == -0x40) {
      return uVar3;
    }
    if (cVar2 != -0x3f) {
      return uVar3;
    }
    if (DAT_ffffd7ee != '\x01') {
      if ((param_3 != '\0') && (param_3 != '\x01')) {
        return uVar3;
      }
      FUN_00065ab8();
      FUN_00065a58();
      return 0x81;
    }
    FUN_00065ab8();
  }
  FUN_00065a58();
  return 0xc0;
}


