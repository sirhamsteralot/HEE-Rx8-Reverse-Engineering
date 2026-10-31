/* ROM address: 0x00065206; body bytes: 106; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063af6 (106 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00065206(short param_1,char param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if ((((param_2 == '\0') || (param_2 == 'P')) || (param_2 == -0x3f)) && (DAT_ffffd7b2 != '\x01')) {
    cVar1 = FUN_0005fcae();
    if (cVar1 == '\0') {
      uVar2 = 0;
    }
    else {
      cVar1 = FUN_000678b4((int)param_1);
      if ((byte)(cVar1 + 1U) < 3) {
        FUN_0006789e();
        uVar2 = 2;
      }
      else {
        FUN_0006789e(3);
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}


