/* ROM address: 0x0004a3fc; body bytes: 360; decompiled */

undefined1 * FUN_0004a3fc(void)

{
  undefined1 *puVar1;
  
  if (DAT_ffffd1c5 == '\0') {
    if (DAT_ffffcd9c == '\x01') {
      if (-0.034 < DAT_ffffcd78) {
        DAT_ffffcdae = rx8_add_u16_saturate((int)(short)DAT_ffffcdae,1);
        if (0x9b < DAT_ffffcdb2) {
          DAT_ffffcd94 = DAT_ffffcd8c;
          DAT_ffffcd96 = DAT_ffffcd8e;
        }
        DAT_ffffcd8c = DAT_ffffcd94;
        DAT_ffffcd8e = DAT_ffffcd96;
        if (0x1d5 < DAT_ffffcdae) {
          DAT_ffffcd7c = 0;
          DAT_ffffcd7d = 0;
          DAT_ffffcd8c = 0;
          DAT_ffffcd8e = 0;
          DAT_ffffcd94 = 0;
          DAT_ffffcd96 = 0;
        }
      }
      else {
        if (0x137 < DAT_ffffcd8c) {
          DAT_ffffcd7d = 1;
        }
        DAT_ffffcd8c = rx8_add_u16_saturate((int)(short)DAT_ffffcd8c,1);
        if (((DAT_ffffcd7d == 1) && (0x137 < DAT_ffffcdaa)) && (DAT_ffffb2f6 == '\0')) {
          if (0x137 < DAT_ffffcd8e) {
            DAT_ffffcd7c = 1;
            DAT_ffffcd7d = 0;
          }
          DAT_ffffcd8e = rx8_add_u16_saturate((int)(short)DAT_ffffcd8e,1);
        }
        else if (DAT_ffffcdb2 < 0x9c) {
          DAT_ffffcd8e = DAT_ffffcd96;
        }
        else {
          DAT_ffffcd96 = DAT_ffffcd8e;
        }
        DAT_ffffcdae = 0;
      }
    }
    else {
      DAT_ffffcdae = 0;
      if (DAT_ffffcdb2 < 0x9c) {
        DAT_ffffcd8c = DAT_ffffcd94;
        DAT_ffffcd8e = DAT_ffffcd96;
      }
      else {
        DAT_ffffcd94 = DAT_ffffcd8c;
        DAT_ffffcd96 = DAT_ffffcd8e;
      }
    }
    puVar1 = (undefined1 *)(uint)DAT_ffffcd7d;
    if (puVar1 == (undefined1 *)0x1) {
      puVar1 = (undefined1 *)rx8_add_u16_saturate((int)(short)DAT_ffffcdaa,1);
      DAT_ffffcdaa = (ushort)puVar1;
    }
    else {
      DAT_ffffcdaa = 0;
    }
  }
  else {
    puVar1 = &DAT_ffffcd7c;
    DAT_ffffcd7c = 0;
    DAT_ffffcd7d = 0;
    DAT_ffffcd8c = 0;
    DAT_ffffcd8e = 0;
    DAT_ffffcdae = 0;
    DAT_ffffcdaa = 0;
  }
  return puVar1;
}


