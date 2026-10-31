/* ROM address: 0x000019ce; body bytes: 106; decompiled_with_warnings */

void FUN_000019ce(int param_1)

{
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x11;
  DAT_ffffdfc8 = 2;
  if (DAT_ffffdfb0 == '\0') {
    DAT_ffffdfcb = 0x22;
  }
  else if (DAT_ffffdfb1 == '\0') {
    DAT_ffffdfcb = 0x33;
  }
  else {
    if ((*(short *)(param_1 + 2) == 1) && (*(char *)(param_1 + 4) == '\x01')) {
      DAT_ffffdfc6 = 0x51;
      DAT_ffffdfc8 = 0;
      FUN_000011fa(&DAT_ffffdfc6);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    DAT_ffffdfcb = 0x12;
  }
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}


