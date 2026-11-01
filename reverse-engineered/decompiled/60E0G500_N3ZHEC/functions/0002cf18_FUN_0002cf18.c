/* ROM address: 0x0002cf18; body bytes: 142; decompiled */

uint FUN_0002cf18(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffb5a4;
  if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffb5aa, uVar1 == 0)) {
    if (DAT_ffffb5b8 < DAT_ffffbc1c * 110.741) {
      if (DAT_ffffb5b8 < DAT_ffffbc1c * 71.887) {
        if (DAT_ffffb5b8 < DAT_ffffbc1c * 52.001) {
          if (DAT_ffffb5b8 < DAT_ffffbc1c * 40.158) {
            if (DAT_ffffb5b8 < DAT_ffffbc1c * 33.841) {
              if (DAT_ffffb5b8 < DAT_ffffbc1c * 0.0) {
                DAT_ffffbca8 = 0;
                return 0;
              }
              uVar1 = 6;
            }
            else {
              uVar1 = 5;
            }
          }
          else {
            uVar1 = 4;
          }
        }
        else {
          uVar1 = 3;
        }
      }
      else {
        uVar1 = 2;
      }
      DAT_ffffbca8 = (undefined1)uVar1;
    }
    else {
      DAT_ffffbca8 = 1;
    }
  }
  else {
    DAT_ffffbca8 = 0;
  }
  return uVar1;
}


