/* ROM address: 0x000046cc; body bytes: 88; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000046cc (88 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_checkFloatValidity_(undefined4 param_1)

{
  undefined4 uVar1;
  uint extraout_fr0;
  undefined1 *local_20 [3];
  undefined1 auStack_14 [12];
  undefined4 uStack_8;
  
  local_20[0] = (undefined1 *)local_20;
  uStack_8 = param_1;
  FUN_000048c8();
  local_20[0] = auStack_14;
  FUN_00004740();
  uVar1 = FUN_0000481c();
  if ((extraout_fr0 & 0x7f800000) == 0x7f800000) {
    if ((extraout_fr0 & 0x7fffff) == 0) {
      DAT_ffff768c = 0x44c;
    }
    else {
      uVar1 = 0x44d;
      DAT_ffff768c = 0x44d;
    }
  }
  return uVar1;
}


