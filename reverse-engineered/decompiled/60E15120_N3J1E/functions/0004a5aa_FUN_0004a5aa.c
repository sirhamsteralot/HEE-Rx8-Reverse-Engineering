/* ROM address: 0x0004a5aa; body bytes: 360; decompiled */

undefined1 * FUN_0004a5aa(void)

{
  undefined1 *puVar1;
  
  if (DAT_ffffd1c5 == '\0') {
    if (DAT_ffffcd9c == '\x01') {
      if (DAT_ffffcd78 < 0.034) {
        DAT_ffffcdb0 = rx8_add_u16_saturate((int)(short)DAT_ffffcdb0,1);
        if (0x9b < DAT_ffffcdb2) {
          DAT_ffffcd98 = DAT_ffffcd90;
          DAT_ffffcd9a = DAT_ffffcd92;
        }
        DAT_ffffcd90 = DAT_ffffcd98;
        DAT_ffffcd92 = DAT_ffffcd9a;
        if (0x1d5 < DAT_ffffcdb0) {
          DAT_ffffcd7e = 0;
          DAT_ffffcd7f = 0;
          DAT_ffffcd90 = 0;
          DAT_ffffcd92 = 0;
          DAT_ffffcd98 = 0;
          DAT_ffffcd9a = 0;
        }
      }
      else {
        if (0x137 < DAT_ffffcd90) {
          DAT_ffffcd7f = 1;
        }
        DAT_ffffcd90 = rx8_add_u16_saturate((int)(short)DAT_ffffcd90,1);
        if (((DAT_ffffcd7f == 1) && (0x137 < DAT_ffffcdac)) && (DAT_ffffb2f6 == '\0')) {
          if (0x137 < DAT_ffffcd92) {
            DAT_ffffcd7e = 1;
            DAT_ffffcd7f = 0;
          }
          DAT_ffffcd92 = rx8_add_u16_saturate((int)(short)DAT_ffffcd92,1);
        }
        else if (DAT_ffffcdb2 < 0x9c) {
          DAT_ffffcd92 = DAT_ffffcd9a;
        }
        else {
          DAT_ffffcd9a = DAT_ffffcd92;
        }
        DAT_ffffcdb0 = 0;
      }
    }
    else {
      DAT_ffffcdb0 = 0;
      if (DAT_ffffcdb2 < 0x9c) {
        DAT_ffffcd90 = DAT_ffffcd98;
        DAT_ffffcd92 = DAT_ffffcd9a;
      }
      else {
        DAT_ffffcd98 = DAT_ffffcd90;
        DAT_ffffcd9a = DAT_ffffcd92;
      }
    }
    puVar1 = (undefined1 *)(uint)DAT_ffffcd7f;
    if (puVar1 == (undefined1 *)0x1) {
      puVar1 = (undefined1 *)rx8_add_u16_saturate((int)(short)DAT_ffffcdac,1);
      DAT_ffffcdac = (ushort)puVar1;
    }
    else {
      DAT_ffffcdac = 0;
    }
  }
  else {
    puVar1 = &DAT_ffffcd7e;
    DAT_ffffcd7e = 0;
    DAT_ffffcd7f = 0;
    DAT_ffffcd90 = 0;
    DAT_ffffcd92 = 0;
    DAT_ffffcdb0 = 0;
    DAT_ffffcdac = 0;
  }
  return puVar1;
}


