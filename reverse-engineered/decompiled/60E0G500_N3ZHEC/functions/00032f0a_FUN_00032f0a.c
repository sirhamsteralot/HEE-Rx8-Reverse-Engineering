/* ROM address: 0x00032f0a; body bytes: 82; decompiled */

uint FUN_00032f0a(void)

{
  uint uVar1;
  
  if (((DAT_ffffbd59 == '\x01') && (DAT_ffffbca1 == 1)) && (0x3d < DAT_ffffc028)) {
    DAT_ffffc022 = 1;
  }
  else {
    DAT_ffffc022 = 0;
  }
  uVar1 = (uint)DAT_ffffbca1;
  if (uVar1 == 1) {
    uVar1 = FUN_00002460((int)(short)DAT_ffffc028,1);
    DAT_ffffc028 = (ushort)uVar1;
  }
  else {
    DAT_ffffc028 = 0;
  }
  return uVar1;
}


