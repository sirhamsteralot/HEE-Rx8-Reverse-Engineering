/* ROM address: 0x0006855c; body bytes: 44; decompiled */

void FUN_0006855c(byte param_1)

{
  short sVar1;
  
  if (*(short *)(&DAT_ffffd998 + (uint)param_1 * 0x46c) == 0) {
    sVar1 = 0x464;
  }
  else {
    sVar1 = *(short *)(&DAT_ffffd998 + (uint)param_1 * 0x46c) + -1;
  }
  *(short *)(&DAT_ffffd99c + (uint)param_1 * 0x46c) = sVar1;
  return;
}


