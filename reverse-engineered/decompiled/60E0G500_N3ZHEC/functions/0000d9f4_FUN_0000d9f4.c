/* ROM address: 0x0000d9f4; body bytes: 160; decompiled */

void FUN_0000d9f4(void)

{
  char cVar1;
  char cVar2;
  undefined *puVar3;
  
  for (DAT_ffffa40e = 0; DAT_ffffa40e < 2; DAT_ffffa40e = DAT_ffffa40e + 1) {
    if (DAT_ffffb5a4 == '\x01') {
      FUN_00009744(0,&DAT_0004e7c8,0x10);
      puVar3 = &DAT_0004e7c8;
    }
    else {
      FUN_00009744(0,&DAT_0004e8c8,0x10);
      puVar3 = &DAT_0004e8c8;
    }
    cVar1 = FUN_0002b088(0,puVar3);
    FUN_00009744(1,&DAT_0004e9c8,6);
    cVar2 = FUN_0002b088(1,&DAT_0004e9c8);
    if (cVar1 == '\0' && cVar2 == '\0') break;
  }
  if (1 < DAT_ffffa40e) {
    DAT_ffffa410 = 1;
  }
  DAT_ffffa411 = 0;
  return;
}


