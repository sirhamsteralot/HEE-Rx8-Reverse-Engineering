/* ROM address: 0x00060c1c; body bytes: 74; decompiled */

undefined4 FUN_00060c1c(ushort param_1)

{
  char cVar1;
  
  cVar1 = FUN_00060154((int)(short)param_1,0x20);
  if (cVar1 == '\0') {
    if ((&DAT_ffffd494)[param_1] != '\x01') {
      return 0;
    }
  }
  else if ((&DAT_ffffd638)[param_1] != -0x40) {
    return 0;
  }
  return 1;
}


