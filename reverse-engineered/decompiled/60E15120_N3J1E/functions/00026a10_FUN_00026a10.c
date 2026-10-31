/* ROM address: 0x00026a10; body bytes: 50; decompiled */

char FUN_00026a10(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffd1c5;
  if ((DAT_ffffd1c5 == '\x01') && (cVar1 = engine_stopped_latch_ffffa41c, engine_stopped_latch_ffffa41c == '\x01')) {
    DAT_ffffb688 = 0;
    DAT_ffffb68a = 0;
    DAT_ffffb68c = 0;
    DAT_ffffb68e = 0;
    DAT_ffffb694 = 0;
  }
  return cVar1;
}


