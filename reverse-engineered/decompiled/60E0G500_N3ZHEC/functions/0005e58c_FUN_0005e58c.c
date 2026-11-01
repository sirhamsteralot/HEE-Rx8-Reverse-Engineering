/* ROM address: 0x0005e58c; body bytes: 48; decompiled */

uint FUN_0005e58c(uint param_1)

{
  param_1 = param_1 & 0xff;
  if (param_1 == 1) {
    param_1 = FUN_000604ee(1);
    DAT_ffffd3b4 = 0;
  }
  else if (param_1 == 2) {
    param_1 = FUN_000604ee(0);
    DAT_ffffd3b4 = 1;
  }
  return param_1;
}


