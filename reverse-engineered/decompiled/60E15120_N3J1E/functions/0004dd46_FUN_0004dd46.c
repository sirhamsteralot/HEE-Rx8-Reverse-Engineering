/* ROM address: 0x0004dd46; body bytes: 60; decompiled */

char FUN_0004dd46(void)

{
  char cVar1;
  char cVar2;
  
  cVar1 = DAT_ffffcf46;
  if (DAT_ffffbfb8 == '\x01') {
    DAT_ffffcf45 = 1;
  }
  if (DAT_ffffbfb6 == '\x01') {
    DAT_ffffcf46 = '\x01';
  }
  cVar2 = DAT_ffffbfb6;
  if ((cVar1 == '\0') && (cVar2 = DAT_ffffcf46, DAT_ffffcf46 == '\x01')) {
    DAT_ffffcf70 = 1;
  }
  return cVar2;
}


