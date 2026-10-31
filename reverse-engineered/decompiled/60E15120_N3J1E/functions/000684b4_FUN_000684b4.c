/* ROM address: 0x000684b4; body bytes: 116; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066da4 (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000684b4(int param_1)

{
  uint local_14;
  uint uStack_10;
  uint local_c;
  
  FUN_00068b22((int)DAT_ffffddec);
  FUN_00068bc6(1,0x28);
  local_14 = (uint)DAT_ffffddea;
  uStack_10 = (uint)DAT_ffffdde6;
  local_c = (uint)(param_1 != 0x7df);
  DAT_ffffddf9 = DAT_ffffddea;
  DAT_ffffddeb = 0;
  DAT_ffffddf5 = DAT_ffffddf5 & 0xfb | 0x40;
  thunk_FUN_00054b2c((int)(char)DAT_ffffddea);
  ref_osTaskScheduler(2,0,&local_14);
  return;
}


