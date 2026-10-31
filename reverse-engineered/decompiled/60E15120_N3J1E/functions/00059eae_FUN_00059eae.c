/* ROM address: 0x00059eae; body bytes: 198; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00058666 (198 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00059eae(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if ((((DAT_ffffd260 == '\0') || (DAT_ffffd25c == '\0')) || (DAT_ffffd259 == '\x01')) ||
     ((DAT_ffffd253 == ' ' || (0x6ddd < DAT_ffffd24e)))) {
    DAT_ffffd253 = '\0';
  }
  else if ((DAT_ffffd253 == '\0') && (DAT_ffffd256 == '\x01')) {
    DAT_ffffd253 = '\x10';
  }
  else if ((DAT_ffffd253 == '\x10') && (DAT_ffffcf79 == '\x01')) {
    DAT_ffffd253 = ' ';
  }
  if (DAT_ffffd253 == '\0') {
    DAT_ffffd26f = 0;
  }
  DAT_ffffd256 = 0;
  DAT_ffffd259 = 0;
  uVar1 = ref_setSR(uVar1);
  if (DAT_ffffd253 == '\0') {
    DAT_ffffd24e = 0;
  }
  else if (DAT_ffffd24e != 0xffff) {
    DAT_ffffd24e = DAT_ffffd24e + 1;
  }
  return uVar1;
}


