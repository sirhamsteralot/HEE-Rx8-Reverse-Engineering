/* ROM address: 0x0004ed0a; body bytes: 86; decompiled */

void FUN_0004ed0a(void)

{
  if (DAT_ffffd2a2 == '\0') {
    DAT_ffffcfc3 = 0;
  }
  else if (DAT_ffffcfc2 == '\x01') {
    DAT_ffffcfc3 = 1;
  }
  if (DAT_ffffcfc1 != '\0') {
    DAT_ffffcfc1 = DAT_ffffcfc1 + -1;
  }
  if ((DAT_ffffcfc4 == '\0') || (DAT_ffffcfc1 != '\0')) {
    DAT_ffffcfc2 = 0;
  }
  else {
    DAT_ffffcfc2 = 1;
  }
  DAT_ffffcfc4 = DAT_ffffcfc1;
  return;
}


