/* ROM address: 0x0004ab02; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00049abe (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_0004ab02(void)

{
  int iVar1;
  
  if ((DAT_ffffcdc6 == '\x01') || (DAT_ffffd1c5 == '\x01')) {
    iVar1 = 1;
    DAT_ffffcdbf = 0;
  }
  else {
    iVar1 = (int)DAT_ffffcdd1;
    if (iVar1 == 0) {
      DAT_ffffcdbf = 1;
    }
  }
  return iVar1;
}


