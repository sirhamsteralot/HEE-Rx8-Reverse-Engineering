/* ROM address: 0x0002eec0; body bytes: 88; decompiled */

void FUN_0002eec0(void)

{
  if (3.0 <= DAT_ffffbc9c) {
    DAT_ffffbdc6 = 0;
  }
  else {
    if (14999 < DAT_ffffbdc6) {
      DAT_ffffbdc4 = '\x01';
    }
    DAT_ffffbdc6 = FUN_00002460((int)(short)DAT_ffffbdc6,1);
  }
  if (DAT_ffffbdc4 == '\x01') {
    FUN_000604dc(0x3f,1);
    return;
  }
  FUN_000604dc(0x3f,2);
  return;
}


