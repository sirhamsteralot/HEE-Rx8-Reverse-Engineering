/* ROM address: 0x0006647c; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064d6c (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0006647c(void)

{
  undefined4 uVar1;
  undefined1 local_18 [4];
  undefined4 local_14;
  uint uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  ref_unknownMode22Func(9);
  DAT_ffffd904 = 1;
  local_18[0] = 0x49;
  ref_setupForUdsResponse_(9,local_18,1);
  FUN_000665cc(6);
  local_14 = 9;
  uStack_10 = (uint)DAT_ffffd904;
  uStack_c = 8;
  uStack_8 = 0;
  uVar1 = FUN_00068d56();
  return uVar1;
}


