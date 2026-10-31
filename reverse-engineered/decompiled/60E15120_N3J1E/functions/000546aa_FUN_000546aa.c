/* ROM address: 0x000546aa; body bytes: 40; decompiled */

char FUN_000546aa(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffc92c;
  if ((DAT_ffffc92c == '\x01') && (cVar1 = DAT_ffffc92e, DAT_ffffc92e == '\x01')) {
    DAT_ffffd1bd = 1;
  }
  else {
    DAT_ffffd1bd = 0;
  }
  return cVar1;
}


