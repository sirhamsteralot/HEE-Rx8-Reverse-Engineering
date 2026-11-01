/* ROM address: 0x00024e5e; body bytes: 490; decompiled */

undefined1 * FUN_00024e5e(void)

{
  char cVar2;
  undefined1 *puVar1;
  
  cVar2 = FUN_000671a4(0x14);
  if ((cVar2 == '\0') && (cVar2 = FUN_000671a4(0x13), cVar2 == '\0')) {
    DAT_ffffb54c = 0;
  }
  else {
    DAT_ffffb54c = 1;
  }
  cVar2 = FUN_000671a4(0x6a);
  DAT_ffffb54d = cVar2 != '\0';
  cVar2 = FUN_000671a4(0x22);
  if ((cVar2 == '\0') && (cVar2 = FUN_000671a4(0x21), cVar2 == '\0')) {
    DAT_ffffb54e = 0;
  }
  else {
    DAT_ffffb54e = 1;
  }
  cVar2 = FUN_000671a4(0x47);
  DAT_ffffb54f = cVar2 != '\0';
  cVar2 = FUN_000671a4(100);
  DAT_ffffb550 = cVar2 != '\0';
  cVar2 = FUN_000671a4(0x5d);
  DAT_ffffb551 = cVar2 != '\0';
  cVar2 = FUN_000671a4(0x5b);
  if ((cVar2 == '\0') && (cVar2 = FUN_000671a4(0x5c), cVar2 == '\0')) {
    DAT_ffffb552 = 0;
  }
  else {
    DAT_ffffb552 = 1;
  }
  cVar2 = FUN_000671a4(0x83);
  DAT_ffffb553 = cVar2 != '\0';
  cVar2 = FUN_000671a4(0x65);
  DAT_ffffb554 = cVar2 != '\0';
  cVar2 = FUN_000671a4(0x4f);
  DAT_ffffb555 = cVar2 != '\0';
  cVar2 = FUN_000671a4(0x61);
  DAT_ffffb556 = cVar2 != '\0';
  cVar2 = FUN_000671a4(0x5f);
  DAT_ffffb557 = cVar2 != '\0';
  cVar2 = FUN_000671a4(0x60);
  DAT_ffffb558 = cVar2 != '\0';
  cVar2 = FUN_000671a4(0x6b);
  DAT_ffffb559 = cVar2 != '\0';
  cVar2 = FUN_000671a4(0x42);
  if (((cVar2 != '\0') ||
      (((DAT_ffffb492 != '\0' && (7500.0 <= DAT_ffffb5b8)) && (DAT_ffffb480 < 13.48)))) ||
     (0.0 < DAT_ffffaa48)) {
    DAT_ffffb55a = 1;
  }
  else {
    DAT_ffffb55a = 0;
  }
  puVar1 = (undefined1 *)0x1;
  if ((DAT_ffffb4ad == '\x01') ||
     (puVar1 = (undefined1 *)(uint)DAT_ffffd201, puVar1 == (undefined1 *)0x1)) {
    DAT_ffffb55b = 1;
  }
  else {
    DAT_ffffb55b = 0;
  }
  if (DAT_ffffbdb4 == '\0') {
    puVar1 = &DAT_ffffb58c;
    DAT_ffffb58c = 1;
  }
  return puVar1;
}


