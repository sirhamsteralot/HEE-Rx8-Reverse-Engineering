/* ROM address: 0x0000d9f4; body bytes: 160; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000d9f4 (160 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_canSetup(void)

{
  char cVar1;
  char cVar2;
  undefined *puVar3;
  
  for (DAT_ffffa40e = 0; DAT_ffffa40e < 2; DAT_ffffa40e = DAT_ffffa40e + 1) {
    if (DAT_ffffb534 == '\x01') {
      ref_CANControllerSetup(0,&DAT_0004e01c,0x10);
      puVar3 = &DAT_0004e01c;
    }
    else {
      ref_CANControllerSetup(0,&DAT_0004e11c,0x10);
      puVar3 = &DAT_0004e11c;
    }
    cVar1 = FUN_0002a4f8(0,puVar3);
    ref_CANControllerSetup(1,&DAT_0004e21c,6);
    cVar2 = FUN_0002a4f8(1,&DAT_0004e21c);
    if (cVar1 == '\0' && cVar2 == '\0') break;
  }
  if (1 < DAT_ffffa40e) {
    DAT_ffffa410 = 1;
  }
  DAT_ffffa411 = 0;
  return;
}


