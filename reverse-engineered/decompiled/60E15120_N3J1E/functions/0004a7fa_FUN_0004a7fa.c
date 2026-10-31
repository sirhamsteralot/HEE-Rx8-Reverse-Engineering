/* ROM address: 0x0004a7fa; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000497b6 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0004a7fa(void)

{
  if (DAT_ffffd1c5 == '\0') {
    if ((DAT_ffffcd7d == '\x01') || (DAT_ffffcd7f == '\x01')) {
      DAT_ffffcd83 = 1;
    }
    else {
      DAT_ffffcd83 = 0;
    }
    if ((DAT_ffffcd7c == '\x01') || (DAT_ffffcd7e == '\x01')) {
      DAT_ffffcd84 = 1;
    }
    else {
      DAT_ffffcd84 = 0;
    }
  }
  else {
    DAT_ffffcd83 = 0;
    DAT_ffffcd84 = 0;
  }
  return;
}


