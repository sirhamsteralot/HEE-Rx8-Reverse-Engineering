/* ROM address: 0x00067db8; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000666a8 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067db8(byte param_1)

{
  short sVar1;
  
  if (*(short *)(&DAT_ffffd95c + (uint)param_1 * 0x46c) == 0) {
    sVar1 = 0x464;
  }
  else {
    sVar1 = *(short *)(&DAT_ffffd95c + (uint)param_1 * 0x46c) + -1;
  }
  *(short *)(&DAT_ffffd960 + (uint)param_1 * 0x46c) = sVar1;
  return;
}


