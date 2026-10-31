/* ROM address: 0x0005e748; body bytes: 74; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005cf54 (74 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005e748(void)

{
  uint uVar1;
  char local_8 [8];
  
  uVar1 = FUN_00037ef0(0x9f,local_8,1);
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 0) {
    uVar1 = (int)local_8[0] & 1;
    if (((uVar1 == 0) && (DAT_ffffd1b5 == '\0')) && (uVar1 = (uint)DAT_ffffd1b8, uVar1 == 0)) {
      DAT_ffffd39c = 1;
    }
    else {
      DAT_ffffd39c = 0;
    }
  }
  return uVar1;
}


