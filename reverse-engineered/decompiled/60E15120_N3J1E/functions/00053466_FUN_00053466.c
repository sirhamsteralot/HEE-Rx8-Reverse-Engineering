/* ROM address: 0x00053466; body bytes: 200; decompiled */

undefined4 * FUN_00053466(void)

{
  undefined4 *puVar1;
  char cVar2;
  float arg1;
  
  arg1 = 0.0;
  puVar1 = (undefined4 *)rx8_is_outside_tolerance_band(DAT_ffffd174,0,0x3727c5ac);
  cVar2 = (char)puVar1;
  if (DAT_ffffcfc6 == '\0') {
    DAT_ffffd180 = 0;
    DAT_ffffd181 = 0;
  }
  else {
    puVar1 = (undefined4 *)(uint)DAT_ffffd180;
    if (puVar1 == (undefined4 *)0x1) {
      DAT_ffffd180 = 0x27;
      DAT_ffffd181 = rx8_add_u8_saturate((int)(char)DAT_ffffd181,1);
      DAT_ffffd168 = DAT_ffffcfe0;
      DAT_ffffd170 = rx8_clamp_float(DAT_ffffcfe0 - DAT_ffffd16c,arg1,0.038);
      if (cVar2 == '\0') {
        DAT_ffffd178 = 100.0;
      }
      else {
        DAT_ffffd178 = (DAT_ffffd170 / DAT_ffffd174) * 100.0;
      }
      DAT_ffffd16c = DAT_ffffd168;
      puVar1 = &DAT_0005354c;
      DAT_ffffd174 = DAT_ffffd170;
      if (2 < DAT_ffffd181) {
        DAT_ffffd17c = DAT_ffffd178;
      }
    }
    else if (DAT_ffffd180 != 0) {
      DAT_ffffd180 = DAT_ffffd180 - 1;
    }
  }
  return puVar1;
}


