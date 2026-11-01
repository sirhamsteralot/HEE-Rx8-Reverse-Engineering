/* ROM address: 0x00059f7c; body bytes: 52; decompiled */

char FUN_00059f7c(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if (((DAT_ffffd29d == '\x01') || (cVar1 = '\x01', DAT_ffffd2a2 == '\x01')) ||
     (cVar1 = DAT_ffffd2ab, DAT_ffffd2ab == '\x01')) {
    DAT_ffffd299 = 1;
  }
  else {
    DAT_ffffd299 = 0;
  }
  return cVar1;
}


