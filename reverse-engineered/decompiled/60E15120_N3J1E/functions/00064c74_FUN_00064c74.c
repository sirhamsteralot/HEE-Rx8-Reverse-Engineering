/* ROM address: 0x00064c74; body bytes: 234; decompiled */

int FUN_00064c74(ushort param_1,char param_2,char param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  cVar1 = (&DAT_ffff8d54)[(uint)param_1 * 2];
  iVar3 = (int)param_2;
  cVar2 = FUN_0006559c((int)param_2);
  if ((cVar2 == '\0') || (cVar2 == 'P')) {
    if ((param_3 == '\0') || (param_3 == '\x01')) {
      iVar3 = 1;
      FUN_00065314();
      FUN_000652b4();
    }
  }
  else if ((cVar2 == '`') || (cVar2 == 'p')) {
    if (DAT_ffffd7b4 == '\0') {
      if (param_3 == '\x01') {
        cVar2 = ref_driveCycleDetectMAYBE_((int)(short)param_1);
        if ((DAT_ffff8e7a._0_1_ == ' ') || (cVar2 == '\0')) {
          iVar3 = 0xc0;
        }
        else if (cVar1 != ' ') {
          FUN_000652b4();
        }
      }
      else if (param_3 == '\0') {
        iVar3 = 0xc0;
      }
    }
  }
  else if (((cVar2 != -0x40) && (cVar2 == -0x3f)) && ((param_3 == '\0' || (param_3 == '\x01')))) {
    iVar3 = 0x81;
    FUN_00065314();
    FUN_000652b4();
  }
  return iVar3;
}


