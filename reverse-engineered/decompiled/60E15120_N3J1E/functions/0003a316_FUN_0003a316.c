/* ROM address: 0x0003a316; body bytes: 192; decompiled */

undefined1 * FUN_0003a316(void)

{
  undefined1 *puVar1;
  uint uVar2;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc542 = 0;
    DAT_ffffc543 = 0;
    DAT_ffffc53f = 0;
    DAT_ffffc540 = 0;
    puVar1 = (undefined1 *)((int)&vector_Poweron_Reset + 1);
  }
  else {
    if (DAT_ffffc541 == '\x01') {
      if (DAT_ffffc544 == '\x01') {
        DAT_ffffc53f = rx8_add_u8_saturate((int)(char)DAT_ffffc53f,1);
      }
      else if (DAT_ffffc545 == '\x01') {
        DAT_ffffc540 = rx8_add_u8_saturate((int)(char)DAT_ffffc540,1);
      }
    }
    puVar1 = (undefined1 *)(uint)secondary_air_pump_request_ffffbf6c;
    if (puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) {
      puVar1 = &DAT_0007a9f0;
      if (DAT_ffffc53f < 0x28) {
        if (0x27 < DAT_ffffc540) {
          uVar2 = ref_getFaultStatus__(0x2b);
          puVar1 = (undefined1 *)(uVar2 & 0xff);
          if (puVar1 == (undefined1 *)0x0) {
            DAT_ffffc543 = 1;
            DAT_ffffc542 = 0;
          }
        }
      }
      else {
        uVar2 = ref_getFaultStatus__(0x2b);
        puVar1 = (undefined1 *)(uVar2 & 0xff);
        if (puVar1 == (undefined1 *)0x0) {
          DAT_ffffc542 = 1;
          DAT_ffffc543 = 0;
        }
      }
    }
  }
  return puVar1;
}


