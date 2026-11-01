/* ROM address: 0x0000cc1e; body bytes: 40; decompiled */

uint FUN_0000cc1e(undefined4 param_1,char param_2)

{
  char *pcVar1;
  uint uVar2;
  
  pcVar1 = (char *)FUN_0000cefe(param_1,&DAT_ffffe400);
  uVar2 = (int)*pcVar1 & 0x7fU | (int)param_2 << 7;
  *pcVar1 = (char)uVar2;
  return uVar2;
}


