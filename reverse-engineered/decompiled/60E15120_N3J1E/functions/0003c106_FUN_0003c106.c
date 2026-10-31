/* ROM address: 0x0003c106; body bytes: 30; decompiled */

void FUN_0003c106(void)

{
  char cVar1;
  
  cVar1 = ref_getFaultStatus__(0x25);
  if (cVar1 == '\0') {
    DAT_ffffc5cb = 1;
  }
  DAT_ffffc5cc = 0;
  FUN_0003c280();
  return;
}


