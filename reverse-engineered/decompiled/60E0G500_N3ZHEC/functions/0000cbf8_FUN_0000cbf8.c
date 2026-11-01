/* ROM address: 0x0000cbf8; body bytes: 38; decompiled */

uint FUN_0000cbf8(undefined4 param_1,char param_2)

{
  char *pcVar1;
  uint uVar2;
  
  pcVar1 = (char *)FUN_0000cefe(param_1,&DAT_ffffe400);
  uVar2 = (int)*pcVar1 & 0xdfU | (int)param_2 << 5;
  *pcVar1 = (char)uVar2;
  return uVar2;
}


