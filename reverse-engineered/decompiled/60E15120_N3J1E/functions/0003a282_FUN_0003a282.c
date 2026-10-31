/* ROM address: 0x0003a282; body bytes: 90; decompiled */

undefined1 * FUN_0003a282(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(uint)DAT_ffffd1c5;
  if ((puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) || (secondary_air_pump_request_ffffbf6c == '\0')) {
    DAT_ffffc541 = 0;
    DAT_ffffc53e = 0;
  }
  else {
    puVar1 = (undefined1 *)rx8_add_u8_saturate((int)(char)DAT_ffffc53e,1);
    DAT_ffffc53e = (byte)puVar1;
    if (DAT_ffffc548 == '\0') {
      DAT_ffffc541 = 0;
    }
    else {
      puVar1 = &DAT_0007a9f2;
      if (0x1f < DAT_ffffc53e) {
        DAT_ffffc541 = 1;
      }
    }
  }
  return puVar1;
}


