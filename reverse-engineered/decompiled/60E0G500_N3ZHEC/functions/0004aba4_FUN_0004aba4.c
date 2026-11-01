/* ROM address: 0x0004aba4; body bytes: 360; decompiled */

undefined1 * FUN_0004aba4(void)

{
  undefined1 *puVar1;
  
  if (DAT_ffffd201 == '\0') {
    if (DAT_ffffcddc == '\x01') {
      if (-0.034 < DAT_ffffcdb8) {
        DAT_ffffcdee = FUN_00002460((int)(short)DAT_ffffcdee,1);
        if (0x9b < DAT_ffffcdf2) {
          DAT_ffffcdd4 = DAT_ffffcdcc;
          DAT_ffffcdd6 = DAT_ffffcdce;
        }
        DAT_ffffcdcc = DAT_ffffcdd4;
        DAT_ffffcdce = DAT_ffffcdd6;
        if (0x1d5 < DAT_ffffcdee) {
          DAT_ffffcdbc = 0;
          DAT_ffffcdbd = 0;
          DAT_ffffcdcc = 0;
          DAT_ffffcdce = 0;
          DAT_ffffcdd4 = 0;
          DAT_ffffcdd6 = 0;
        }
      }
      else {
        if (0x137 < DAT_ffffcdcc) {
          DAT_ffffcdbd = 1;
        }
        DAT_ffffcdcc = FUN_00002460((int)(short)DAT_ffffcdcc,1);
        if (((DAT_ffffcdbd == 1) && (0x137 < DAT_ffffcdea)) && (DAT_ffffb366 == '\0')) {
          if (0x137 < DAT_ffffcdce) {
            DAT_ffffcdbc = 1;
            DAT_ffffcdbd = 0;
          }
          DAT_ffffcdce = FUN_00002460((int)(short)DAT_ffffcdce,1);
        }
        else if (DAT_ffffcdf2 < 0x9c) {
          DAT_ffffcdce = DAT_ffffcdd6;
        }
        else {
          DAT_ffffcdd6 = DAT_ffffcdce;
        }
        DAT_ffffcdee = 0;
      }
    }
    else {
      DAT_ffffcdee = 0;
      if (DAT_ffffcdf2 < 0x9c) {
        DAT_ffffcdcc = DAT_ffffcdd4;
        DAT_ffffcdce = DAT_ffffcdd6;
      }
      else {
        DAT_ffffcdd4 = DAT_ffffcdcc;
        DAT_ffffcdd6 = DAT_ffffcdce;
      }
    }
    puVar1 = (undefined1 *)(uint)DAT_ffffcdbd;
    if (puVar1 == (undefined1 *)0x1) {
      puVar1 = (undefined1 *)FUN_00002460((int)(short)DAT_ffffcdea,1);
      DAT_ffffcdea = (ushort)puVar1;
    }
    else {
      DAT_ffffcdea = 0;
    }
  }
  else {
    puVar1 = &DAT_ffffcdbc;
    DAT_ffffcdbc = 0;
    DAT_ffffcdbd = 0;
    DAT_ffffcdcc = 0;
    DAT_ffffcdce = 0;
    DAT_ffffcdee = 0;
    DAT_ffffcdea = 0;
  }
  return puVar1;
}


