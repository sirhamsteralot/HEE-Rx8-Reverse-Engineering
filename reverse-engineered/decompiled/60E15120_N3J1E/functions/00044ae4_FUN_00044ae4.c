/* ROM address: 0x00044ae4; body bytes: 50; decompiled */

char FUN_00044ae4(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffd1c5;
  if ((DAT_ffffd1c5 == '\x01') && (cVar1 = engine_stopped_latch_ffffa41c, engine_stopped_latch_ffffa41c == '\x01')) {
    DAT_ffffcb9d = 0;
    DAT_ffffcb9e = 0;
    DAT_ffffcb9c = 0;
    DAT_ffffcb9f = 0;
    DAT_ffffcba0 = 0;
  }
  return cVar1;
}


