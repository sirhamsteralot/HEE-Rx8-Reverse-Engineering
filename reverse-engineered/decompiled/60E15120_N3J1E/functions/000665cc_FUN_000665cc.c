/* ROM address: 0x000665cc; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064ebc (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000665cc(char param_1)

{
  ushort uVar1;
  uint uVar2;
  char local_d [5];
  
  local_d[0] = param_1;
  uVar2 = ref_OBDModeFunc_Unsure((int)param_1,&DAT_ffffd906);
  if ((uVar2 & 0xff) != 0) {
    ref_setupForUdsResponse_(9,local_d,1);
    uVar1 = (ushort)uVar2;
    DAT_ffffd904 = DAT_ffffd904 + 1;
    uVar2 = ref_setupForUdsResponse_(9,&DAT_ffffd906);
    DAT_ffffd904 = DAT_ffffd904 + (uVar1 & 0xff);
  }
  return uVar2;
}


