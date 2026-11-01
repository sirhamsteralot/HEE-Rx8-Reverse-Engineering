/* ROM address: 0x0004897a; body bytes: 48; decompiled */

void FUN_0004897a(void)

{
  if (DAT_ffffccd2 == '\0') {
    DAT_ffffcce2 = 0;
    DAT_ffffcce3 = 0;
  }
  else if (DAT_ffffccd2 == '\x01') {
    DAT_ffffcce2 = 0;
    DAT_ffffcce3 = 1;
  }
  else {
    DAT_ffffcce2 = 1;
    DAT_ffffcce3 = 0;
  }
  return;
}


