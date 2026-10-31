/* ROM address: 0x00044558; body bytes: 50; decompiled */

char FUN_00044558(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffd1c5;
  if ((DAT_ffffd1c5 == '\x01') && (cVar1 = engine_stopped_latch_ffffa41c, engine_stopped_latch_ffffa41c == '\x01')) {
    DAT_ffffcb6d = 0;
    DAT_ffffcb6e = 0;
    DAT_ffffcb6c = 0;
    DAT_ffffcb6f = 0;
    DAT_ffffcb70 = 0;
  }
  return cVar1;
}


