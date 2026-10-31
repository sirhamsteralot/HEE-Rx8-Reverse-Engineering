/* ROM address: 0x00064b30; body bytes: 292; decompiled */

uint FUN_00064b30(ushort param_1,char param_2,char param_3)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  
  cVar1 = (&DAT_ffff8d54)[(uint)param_1 * 2];
  uVar3 = (uint)param_2;
  cVar2 = FUN_0006559c((int)param_2);
  if ((cVar2 == '\0') || (cVar2 == 'P')) {
    if (DAT_ffffd7b2 != '\x01') {
      if ((param_3 != '\0') && (param_3 != '\x01')) {
        return uVar3;
      }
      FUN_00065314();
      FUN_000652b4();
      return 1;
    }
    FUN_00065314();
  }
  else {
    if ((cVar2 == '`') || (cVar2 == 'p')) {
      if ((DAT_ffffd7b3 == '\0') &&
         (((cVar2 = ref_driveCycleDetectMAYBE_((int)(short)param_1), DAT_ffff8e78._0_1_ == ' ' ||
           (cVar2 == '\0')) || (DAT_ffffd7b2 == '\x01')))) {
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
      FUN_000652b4();
      return uVar3;
    }
    if (cVar2 == -0x40) {
      return uVar3;
    }
    if (cVar2 != -0x3f) {
      return uVar3;
    }
    if (DAT_ffffd7b2 != '\x01') {
      if ((param_3 != '\0') && (param_3 != '\x01')) {
        return uVar3;
      }
      FUN_00065314();
      FUN_000652b4();
      return 0x81;
    }
    FUN_00065314();
  }
  FUN_000652b4();
  return 0xc0;
}


