/* ROM address: 0x00056b82; body bytes: 74; decompiled_with_warnings */

char FUN_00056b82(char param_1)

{
  char cVar1;
  
  cVar1 = DAT_ffffd218;
  if (param_1 == '\x03') {
    DAT_ffffd218 = 3;
  }
  else if (param_1 == '\x01') {
    if (DAT_ffffd218 == '\x03') {
      FUN_00056c78();
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    DAT_ffffd218 = 0;
    param_1 = cVar1;
  }
  else {
    DAT_ffffd218 = 0;
  }
  return param_1;
}


