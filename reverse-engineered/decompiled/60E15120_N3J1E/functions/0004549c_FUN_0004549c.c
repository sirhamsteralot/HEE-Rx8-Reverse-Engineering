/* ROM address: 0x0004549c; body bytes: 28; decompiled */

void FUN_0004549c(byte param_1)

{
  char *pcVar1;
  
  pcVar1 = &DAT_ffffcbbe + param_1;
  if (*pcVar1 != -1) {
    *pcVar1 = *pcVar1 + '\x01';
  }
  return;
}


