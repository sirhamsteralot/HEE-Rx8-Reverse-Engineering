/* ROM address: 0x0006892a; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006721a (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006892a(void)

{
  int iVar1;
  
  FUN_00068c58(3);
  if (DAT_ffffddf6 == '\x01') {
    FUN_00068bc6(1,0xf96);
    DAT_ffffddf5 = DAT_ffffddf5 & 0xef;
    iVar1 = 0x7f;
  }
  else {
    FUN_00068c58(1);
    FUN_00068c58(0);
    FUN_00068910();
    iVar1 = (int)DAT_ffffdde0;
  }
  thunk_FUN_00054a36(iVar1);
  return;
}


