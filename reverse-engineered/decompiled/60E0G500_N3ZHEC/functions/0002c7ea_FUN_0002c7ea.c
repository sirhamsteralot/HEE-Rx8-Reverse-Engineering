/* ROM address: 0x0002c7ea; body bytes: 134; decompiled */

uint FUN_0002c7ea(void)

{
  uint uVar1;
  
  if (-5.0 <= DAT_ffffaa10) {
    DAT_ffffbc98 = 1;
  }
  if (-5.0 <= DAT_ffffae54) {
    DAT_ffffbc99 = 1;
  }
  uVar1 = (uint)DAT_ffffbc98;
  if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffbc99, uVar1 == 1)) {
    uVar1 = FUN_00002478(10,1);
    DAT_ffffbc97 = (byte)uVar1;
  }
  if (DAT_ffffbc97 != 0) {
    DAT_ffffbc8c = 0xffe20000;
  }
  else {
    DAT_ffffbc8c = 0;
  }
  DAT_ffffbc96 = DAT_ffffbc97 != 0;
  if (DAT_ffffbc97 < 0x65) {
    DAT_ffffbc90 = 0;
  }
  else {
    DAT_ffffbc90 = 0xffe20000;
  }
  return uVar1;
}


