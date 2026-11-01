/* ROM address: 0x00008d30; body bytes: 86; decompiled */

void FUN_00008d30(uint param_1)

{
  int iVar1;
  undefined4 local_10 [2];
  
  FUN_00002054(local_10,0xe0);
  iVar1 = (param_1 & 0xff) * 8;
  if ((&DAT_ffffa0dc)[iVar1] == '\0') {
    FUN_00009440(param_1,0);
    *(undefined2 *)(&PTR_DAT_0000d82c)[(param_1 & 0xff) * 6] =
         *(undefined2 *)(&DAT_0000d830 + (param_1 & 0xff) * 0x18);
    (&DAT_ffffa0dd)[iVar1] = 0;
  }
  FUN_00002064(local_10[0]);
  return;
}


