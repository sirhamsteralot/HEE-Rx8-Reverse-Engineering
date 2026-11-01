/* ROM address: 0x0000b23c; body bytes: 84; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0000b25e) */

void FUN_0000b23c(void)

{
  byte bVar1;
  undefined4 local_10 [2];
  
  DAT_ffffa214 = 0;
  DAT_ffffa210 = 0;
  FUN_00002054(local_10,0xe0);
  bVar1 = DAT_fffff400;
  DAT_fffff400 = bVar1 & 0x7f;
  DAT_fffff58e = 1;
  DAT_fffff586 = 1;
  DAT_fffff596 = 1;
  DAT_fffff59e = 1;
  DAT_fffff596 = 0;
  bVar1 = DAT_fffff400;
  DAT_fffff400 = bVar1 | 0x80;
  FUN_00002064(local_10[0]);
  return;
}


