/* ROM address: 0x00055cb0; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00053fcc (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_runSubfunction__(char param_1)

{
  undefined4 uVar1;
  
  DAT_ffffd1cf = param_1;
  FUN_00055ce4(0);
  DAT_ffffd1d1 = FUN_00056320((int)param_1);
  DAT_ffffde20 = DAT_ffffd1d1;
  FUN_0005bf50();
  if (DAT_ffffd1cf == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = 3;
  }
  FUN_00055cec(uVar1);
  return;
}


