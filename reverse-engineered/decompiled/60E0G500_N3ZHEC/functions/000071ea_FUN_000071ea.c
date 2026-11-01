/* ROM address: 0x000071ea; body bytes: 98; decompiled */

int sci0_exchange_byte_wait_rdrf(undefined1 param_1)

{
  byte bVar1;
  char cVar2;
  
  FUN_00004c14();
  FUN_00004bbc(0xfffff764,1,0);
  FUN_00004c14();
  bVar1 = DAT_fffff004;
  DAT_fffff004 = bVar1 & 0x87 | 0x80;
  DAT_fffff003 = param_1;
  bVar1 = DAT_fffff004;
  DAT_fffff004 = bVar1 & 0x7f | 0x78;
  do {
    bVar1 = DAT_fffff004;
  } while ((bVar1 & 0x40) == 0);
  cVar2 = DAT_fffff005;
  bVar1 = DAT_fffff004;
  DAT_fffff004 = bVar1 & 0xbf | 0xb8;
  FUN_00004c14();
  FUN_00004bbc(0xfffff764,1);
  return (int)cVar2;
}


