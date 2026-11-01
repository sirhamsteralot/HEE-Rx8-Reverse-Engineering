/* ROM address: 0x00053c0a; body bytes: 200; decompiled */

undefined4 * FUN_00053c0a(void)

{
  undefined4 *puVar1;
  char cVar2;
  float arg1;
  
  arg1 = 0.0;
  puVar1 = (undefined4 *)FUN_00002440(DAT_ffffd1b0,0,0x3727c5ac);
  cVar2 = (char)puVar1;
  if (DAT_ffffd002 == '\0') {
    DAT_ffffd1bc = 0;
    DAT_ffffd1bd = 0;
  }
  else {
    puVar1 = (undefined4 *)(uint)DAT_ffffd1bc;
    if (puVar1 == (undefined4 *)0x1) {
      DAT_ffffd1bc = 0x27;
      DAT_ffffd1bd = FUN_00002478((int)(char)DAT_ffffd1bd,1);
      DAT_ffffd1a4 = DAT_ffffd01c;
      DAT_ffffd1ac = rx8_clamp_float(DAT_ffffd01c - DAT_ffffd1a8,arg1,0.038);
      if (cVar2 == '\0') {
        DAT_ffffd1b4 = 100.0;
      }
      else {
        DAT_ffffd1b4 = (DAT_ffffd1ac / DAT_ffffd1b0) * 100.0;
      }
      DAT_ffffd1a8 = DAT_ffffd1a4;
      puVar1 = &DAT_00053cf0;
      DAT_ffffd1b0 = DAT_ffffd1ac;
      if (2 < DAT_ffffd1bd) {
        DAT_ffffd1b8 = DAT_ffffd1b4;
      }
    }
    else if (DAT_ffffd1bc != 0) {
      DAT_ffffd1bc = DAT_ffffd1bc - 1;
    }
  }
  return puVar1;
}


