/* ROM address: 0x00065980; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064270 (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00065980(char param_1)

{
  uint uVar1;
  short sVar2;
  undefined1 auStack_14 [7];
  char local_d [5];
  
  local_d[0] = param_1;
  uVar1 = jump_to_FUN_00054d90((int)param_1);
  if ((uVar1 & 0xff) != 0) {
    ref_setupForUdsResponse_(1,local_d);
    DAT_ffffd816 = DAT_ffffd816 + 1;
    sVar2 = (short)(uVar1 & 0xff);
    ref_setupForUdsResponse_(1,auStack_14,uVar1 & 0xff);
    uVar1 = (uint)sVar2;
    DAT_ffffd816 = DAT_ffffd816 + sVar2;
  }
  return uVar1;
}


