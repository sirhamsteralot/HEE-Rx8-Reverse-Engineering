/* ROM address: 0x00067de4; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000666d4 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067de4(byte param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = (uint)param_1 * 0x46c;
  if (*(ushort *)(&DAT_ffffd960 + iVar2) < 0x464) {
    sVar1 = *(short *)(&DAT_ffffd960 + iVar2) + 1;
  }
  else {
    sVar1 = 0;
  }
  *(short *)(&DAT_ffffd95e + iVar2) = sVar1;
  return;
}


