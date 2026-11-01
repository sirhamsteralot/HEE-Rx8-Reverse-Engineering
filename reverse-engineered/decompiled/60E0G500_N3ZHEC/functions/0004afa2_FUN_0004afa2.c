/* ROM address: 0x0004afa2; body bytes: 84; decompiled */

void FUN_0004afa2(void)

{
  if (DAT_ffffd201 == '\0') {
    if ((DAT_ffffcdbd == '\x01') || (DAT_ffffcdbf == '\x01')) {
      DAT_ffffcdc3 = 1;
    }
    else {
      DAT_ffffcdc3 = 0;
    }
    if ((DAT_ffffcdbc == '\x01') || (DAT_ffffcdbe == '\x01')) {
      DAT_ffffcdc4 = 1;
    }
    else {
      DAT_ffffcdc4 = 0;
    }
  }
  else {
    DAT_ffffcdc3 = 0;
    DAT_ffffcdc4 = 0;
  }
  return;
}


