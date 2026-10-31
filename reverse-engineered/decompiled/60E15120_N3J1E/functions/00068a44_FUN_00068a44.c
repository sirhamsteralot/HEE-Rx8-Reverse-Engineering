/* ROM address: 0x00068a44; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067334 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068a44(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_00068c58(5);
  DAT_ffffddef = rx8_add_u8_saturate((int)DAT_ffffddef,1);
  if (DAT_ffffddf8 == '\x01') {
    uVar2 = 5;
    DAT_ffffddeb = 2;
    uVar1 = 6;
  }
  else {
    uVar2 = 0x96;
    uVar1 = 5;
    DAT_ffffddef = 0;
    DAT_ffffddeb = 4;
  }
  FUN_00068bc6(uVar1,uVar2);
  return;
}


