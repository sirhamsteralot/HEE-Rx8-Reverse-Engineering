/* ROM address: 0x00045030; body bytes: 36; decompiled */

char FUN_00045030(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffcbb0;
  if ((DAT_ffffcbb0 == '\x01') && (cVar1 = engine_running_ffffa428, engine_running_ffffa428 == '\x01')) {
    DAT_ffffcbb5 = 0x40;
  }
  return cVar1;
}


