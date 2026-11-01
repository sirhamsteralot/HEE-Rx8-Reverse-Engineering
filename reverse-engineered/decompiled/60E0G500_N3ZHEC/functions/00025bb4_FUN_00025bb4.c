/* ROM address: 0x00025bb4; body bytes: 134; decompiled */

void FUN_00025bb4(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffb5db;
  DAT_ffffb5dc = DAT_ffffb5db;
  if (DAT_ffffb5d9 == '\x01') {
    DAT_ffffb5d9 = '\0';
    DAT_ffffb5da = '@';
    DAT_ffffb5db = '\x01';
  }
  else if ((DAT_ffffb5da != '\0') && (DAT_ffffb5da = DAT_ffffb5da + -1, DAT_ffffb5da == '\0')) {
    DAT_ffffb5db = '\0';
  }
  if ((DAT_ffffb5db == '\0') && (cVar1 == '\x01')) {
    DAT_ffffb5d8 = '\f';
  }
  else if ((DAT_ffffb5db == '\x01') && (DAT_ffffb5d8 != '\0')) {
    DAT_ffffb5d8 = DAT_ffffb5d8 + -1;
  }
  FUN_000074e0(DAT_ffffb5d8 != '\0');
  return;
}


