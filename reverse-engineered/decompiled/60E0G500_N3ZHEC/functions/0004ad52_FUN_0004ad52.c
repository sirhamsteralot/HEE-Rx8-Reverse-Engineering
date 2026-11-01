/* ROM address: 0x0004ad52; body bytes: 360; decompiled */

undefined1 * FUN_0004ad52(void)

{
  undefined1 *puVar1;
  
  if (DAT_ffffd201 == '\0') {
    if (DAT_ffffcddc == '\x01') {
      if (DAT_ffffcdb8 < 0.034) {
        DAT_ffffcdf0 = FUN_00002460((int)(short)DAT_ffffcdf0,1);
        if (0x9b < DAT_ffffcdf2) {
          DAT_ffffcdd8 = DAT_ffffcdd0;
          DAT_ffffcdda = DAT_ffffcdd2;
        }
        DAT_ffffcdd0 = DAT_ffffcdd8;
        DAT_ffffcdd2 = DAT_ffffcdda;
        if (0x1d5 < DAT_ffffcdf0) {
          DAT_ffffcdbe = 0;
          DAT_ffffcdbf = 0;
          DAT_ffffcdd0 = 0;
          DAT_ffffcdd2 = 0;
          DAT_ffffcdd8 = 0;
          DAT_ffffcdda = 0;
        }
      }
      else {
        if (0x137 < DAT_ffffcdd0) {
          DAT_ffffcdbf = 1;
        }
        DAT_ffffcdd0 = FUN_00002460((int)(short)DAT_ffffcdd0,1);
        if (((DAT_ffffcdbf == 1) && (0x137 < DAT_ffffcdec)) && (DAT_ffffb366 == '\0')) {
          if (0x137 < DAT_ffffcdd2) {
            DAT_ffffcdbe = 1;
            DAT_ffffcdbf = 0;
          }
          DAT_ffffcdd2 = FUN_00002460((int)(short)DAT_ffffcdd2,1);
        }
        else if (DAT_ffffcdf2 < 0x9c) {
          DAT_ffffcdd2 = DAT_ffffcdda;
        }
        else {
          DAT_ffffcdda = DAT_ffffcdd2;
        }
        DAT_ffffcdf0 = 0;
      }
    }
    else {
      DAT_ffffcdf0 = 0;
      if (DAT_ffffcdf2 < 0x9c) {
        DAT_ffffcdd0 = DAT_ffffcdd8;
        DAT_ffffcdd2 = DAT_ffffcdda;
      }
      else {
        DAT_ffffcdd8 = DAT_ffffcdd0;
        DAT_ffffcdda = DAT_ffffcdd2;
      }
    }
    puVar1 = (undefined1 *)(uint)DAT_ffffcdbf;
    if (puVar1 == (undefined1 *)0x1) {
      puVar1 = (undefined1 *)FUN_00002460((int)(short)DAT_ffffcdec,1);
      DAT_ffffcdec = (ushort)puVar1;
    }
    else {
      DAT_ffffcdec = 0;
    }
  }
  else {
    puVar1 = &DAT_ffffcdbe;
    DAT_ffffcdbe = 0;
    DAT_ffffcdbf = 0;
    DAT_ffffcdd0 = 0;
    DAT_ffffcdd2 = 0;
    DAT_ffffcdf0 = 0;
    DAT_ffffcdec = 0;
  }
  return puVar1;
}


