/* ROM address: 0x0000b308; body bytes: 100; decompiled */

void FUN_0000b308(void)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 local_10 [2];
  
  if (DAT_ffffa214 == '\0') {
    uVar2 = FUN_0000231c(DAT_ffffa210,32000);
    FUN_00002054(local_10,0xe0);
    DAT_ffff9f50 = 32000;
    bVar1 = DAT_fffff400;
    DAT_fffff400 = bVar1 & 0x7f;
    DAT_fffff58e = 32000;
    DAT_fffff586 = 32000;
    DAT_fffff596 = 32000;
    DAT_fffff59e = 32000;
    DAT_fffff596 = uVar2;
    bVar1 = DAT_fffff400;
    DAT_fffff400 = bVar1 | 0x80;
    FUN_00002064(local_10[0]);
    DAT_ffffa214 = '\x01';
  }
  return;
}


