/* ROM address: 0x00065418; body bytes: 234; decompiled */

int FUN_00065418(ushort param_1,char param_2,char param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  cVar1 = (&DAT_ffff8d7c)[(uint)param_1 * 2];
  iVar3 = (int)param_2;
  cVar2 = FUN_00065d40((int)param_2);
  if ((cVar2 == '\0') || (cVar2 == 'P')) {
    if ((param_3 == '\0') || (param_3 == '\x01')) {
      iVar3 = 1;
      FUN_00065ab8();
      FUN_00065a58();
    }
  }
  else if ((cVar2 == '`') || (cVar2 == 'p')) {
    if (DAT_ffffd7f0 == '\0') {
      if (param_3 == '\x01') {
        cVar2 = FUN_00065e34((int)(short)param_1);
        if ((DAT_ffff8ea2._0_1_ == ' ') || (cVar2 == '\0')) {
          iVar3 = 0xc0;
        }
        else if (cVar1 != ' ') {
          FUN_00065a58();
        }
      }
      else if (param_3 == '\0') {
        iVar3 = 0xc0;
      }
    }
  }
  else if (((cVar2 != -0x40) && (cVar2 == -0x3f)) && ((param_3 == '\0' || (param_3 == '\x01')))) {
    iVar3 = 0x81;
    FUN_00065ab8();
    FUN_00065a58();
  }
  return iVar3;
}


