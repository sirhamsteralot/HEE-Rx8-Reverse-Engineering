/* ROM address: 0x000423a8; body bytes: 200; decompiled */

void FUN_000423a8(void)

{
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc98c = 0;
    DAT_ffffc98a = 0;
    DAT_ffffc988 = 0;
    DAT_ffffc986 = 0;
    DAT_ffffc984 = 0;
    DAT_ffffc982 = 0;
    DAT_ffffc97e = 0;
    DAT_ffffc97d = 0;
    DAT_ffffc97c = 0;
    DAT_ffffc97b = 0;
    DAT_ffffc97a = 0;
    DAT_ffffc979 = 0;
    return;
  }
  if (DAT_ffffc978 == '\x01') {
    if (DAT_ffffa1dc == '\x01') {
      if (DAT_ffffc982 == 4) {
        DAT_ffffc979 = 1;
      }
      DAT_ffffc982 = rx8_add_u16_saturate((int)DAT_ffffc982,1);
      DAT_ffffc984 = 0;
    }
    else {
      if (DAT_ffffa1dc != '\x02') {
        if (DAT_ffffc986 == 8) {
          DAT_ffffc97b = 1;
        }
        DAT_ffffc986 = rx8_add_u16_saturate((int)DAT_ffffc986,1);
        DAT_ffffc982 = 0;
        DAT_ffffc984 = 0;
        if (DAT_ffffa1dd == '\x01') {
          if (DAT_ffffc988 == 4) {
            DAT_ffffc97c = 1;
          }
          DAT_ffffc988 = rx8_add_u16_saturate((int)DAT_ffffc988,1);
          DAT_ffffc98a = 0;
        }
        else {
          if (DAT_ffffa1dd != '\x02') {
            if (DAT_ffffc98c == 8) {
              DAT_ffffc97e = 1;
            }
            DAT_ffffc98c = rx8_add_u16_saturate((int)DAT_ffffc98c,1);
            DAT_ffffc988 = 0;
            DAT_ffffc98a = 0;
            return;
          }
          if (DAT_ffffc98a == 4) {
            DAT_ffffc97d = 1;
          }
          DAT_ffffc98a = rx8_add_u16_saturate((int)DAT_ffffc98a,1);
          DAT_ffffc988 = 0;
        }
        DAT_ffffc98c = 0;
        return;
      }
      if (DAT_ffffc984 == 4) {
        DAT_ffffc97a = 1;
      }
      DAT_ffffc984 = rx8_add_u16_saturate((int)DAT_ffffc984,1);
      DAT_ffffc982 = 0;
    }
    DAT_ffffc986 = 0;
    FUN_000424be();
    return;
  }
  FUN_0004252a();
  return;
}


