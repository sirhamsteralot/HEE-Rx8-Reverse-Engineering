/* ROM address: 0x0005ef44; body bytes: 68; decompiled */

char FUN_0005ef44(void)

{
  char cVar1;
  undefined2 local_c;
  
  cVar1 = FUN_00038ed8(0x78,&local_c,2);
  if (cVar1 == '\0') {
    cVar1 = (char)local_c;
  }
  else {
    local_c = 0xffff;
  }
  DAT_ffffd3dc = local_c;
  DAT_ffffd3e4 = local_c;
  DAT_ffffd3eb = 0;
  DAT_ffffd3ea = 0;
  return cVar1;
}


