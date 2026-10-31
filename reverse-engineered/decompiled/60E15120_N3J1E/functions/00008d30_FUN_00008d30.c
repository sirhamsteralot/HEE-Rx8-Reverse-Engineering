/* ROM address: 0x00008d30; body bytes: 86; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00008d30 (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00008d30(uint param_1)

{
  int iVar1;
  undefined4 local_10 [2];
  
  ref_setSR_PARAM(local_10,0xe0);
  iVar1 = (param_1 & 0xff) * 8;
  if ((&DAT_ffffa0dc)[iVar1] == '\0') {
    FUN_00009440(param_1,0);
    *(undefined2 *)(&PTR_ATUII_DSTR_W_0000d82c)[(param_1 & 0xff) * 6] =
         *(undefined2 *)(&DAT_0000d830 + (param_1 & 0xff) * 0x18);
    (&DAT_ffffa0dd)[iVar1] = 0;
  }
  FUN_00002064(local_10[0]);
  return;
}


