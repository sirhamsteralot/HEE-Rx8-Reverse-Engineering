/* ROM address: 0x0000cd40; body bytes: 34; decompiled */

byte FUN_0000cd40(byte param_1)

{
  int iVar1;
  
  iVar1 = FUN_0000cee8((int)(char)param_1,&DAT_ffffe420);
  return *(byte *)(iVar1 + (param_1 & 0xf) * 8) & 0xf;
}


