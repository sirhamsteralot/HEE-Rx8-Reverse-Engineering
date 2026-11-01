/* ROM address: 0x000646a0; body bytes: 76; decompiled */

void FUN_000646a0(void)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = (int)DAT_ffff8e94._0_1_;
  pcVar1 = &DAT_ffff8d7c;
  do {
    iVar2 = iVar2 + *pcVar1;
    DAT_ffff8e94 = FUN_00002420(iVar2);
    *pcVar1 = '\0';
    DAT_ffff8e96 = FUN_00002420(iVar2);
    pcVar1 = pcVar1 + 2;
  } while (pcVar1 < &DAT_ffff8e94);
  return;
}


