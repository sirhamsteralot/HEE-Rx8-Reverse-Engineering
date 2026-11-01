/* ROM address: 0x00054b88; body bytes: 66; decompiled */

char FUN_00054b88(void)

{
  char cVar1;
  char local_8 [8];
  
  cVar1 = FUN_00038ed8(0x95,local_8,1);
  if (cVar1 == '\0') {
    if (local_8[0] == '*') {
      DAT_ffffd1f1 = 0;
      cVar1 = '*';
    }
    else {
      cVar1 = '\x01';
      DAT_ffffd1f1 = 1;
    }
  }
  return cVar1;
}


