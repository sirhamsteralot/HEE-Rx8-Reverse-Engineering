/* ROM address: 0x00065f96; body bytes: 78; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064886 (78 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00065f96(undefined1 param_1,undefined1 param_2)

{
  undefined2 local_14 [3];
  undefined1 local_e;
  undefined1 local_d [5];
  
  local_14[0] = 0;
  local_e = param_2;
  local_d[0] = param_1;
  ref_setupForUdsResponse_(2,local_d,1);
  ref_setupForUdsResponse_(2,&local_e,1);
  DAT_ffffd818 = DAT_ffffd818 + 2;
  ref_setupForUdsResponse_(2,local_14);
  DAT_ffffd818 = DAT_ffffd818 + 2;
  return;
}


