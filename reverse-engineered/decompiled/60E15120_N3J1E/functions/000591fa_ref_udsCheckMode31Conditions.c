/* ROM address: 0x000591fa; body bytes: 152; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00057996 (152 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_udsCheckMode31Conditions(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((((((DAT_ffffd1ad == '\x01') || (DAT_ffffd261 == '\x01')) || (DAT_ffffd266 == '\x01')) ||
       (DAT_ffffd26f == '\x01')) ||
      (((cVar1 = FUN_00055e3e(0), cVar1 == '\x01' && (cVar1 = FUN_00055e3e(2), cVar1 == '\x01')) ||
       ((param_1 == '\x02' && (DAT_ffffd25e == '\0')))))) ||
     (((param_1 == -0x7e && (DAT_ffffd25f == '\0')) ||
      ((param_1 == '\x0f' && (DAT_ffffd260 == '\0')))))) {
    uVar2 = 1;
  }
  return uVar2;
}


