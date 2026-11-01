/* ROM address: 0x0002e2cc; body bytes: 88; decompiled */

void FUN_0002e2cc(void)

{
  if (3.0 <= inferred_ram_bc30_ffffbc30_ffffbc30) {
    DAT_ffffbd5a = 0;
  }
  else {
    if (14999 < DAT_ffffbd5a) {
      DAT_ffffbd58 = '\x01';
    }
    DAT_ffffbd5a = rx8_add_u16_saturate((int)(short)DAT_ffffbd5a,1);
  }
  if (DAT_ffffbd58 == '\x01') {
    FUN_0005fd38(0x3f,1);
    return;
  }
  FUN_0005fd38(0x3f,2);
  return;
}


