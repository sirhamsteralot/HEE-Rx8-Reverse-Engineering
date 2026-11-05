/* ROM address: 0x0005a130; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000588e8 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_faultSomething0x1(void)

{
  uint uVar1;
  
  uVar1 = FUN_00061450(0x80);
  if (((uVar1 & 0xffff) == 0) || (uVar1 = (uint)DAT_ffffd1c5, uVar1 == 1)) {
    mil_lamp_flag_ffffd286 = 0;
  }
  else {
    mil_lamp_flag_ffffd286 = 1;
  }
  return uVar1;
}


