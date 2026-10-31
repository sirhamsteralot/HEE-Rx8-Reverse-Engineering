/* ROM address: 0x00009114; body bytes: 178; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009114 (178 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * FUN_00009114(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  float fVar3;
  undefined4 local_14 [2];
  
  iVar2 = (param_1 & 0xff) * 8;
  if ((&DAT_ffffa0dd)[iVar2] == '\0') {
    fVar3 = *(float *)(&DAT_ffffa0d8 + iVar2) - DAT_ffffa0fc;
    if (-90.0 <= fVar3) {
      if (630.0 <= fVar3) {
        fVar3 = fVar3 + -720.0;
      }
    }
    else {
      fVar3 = fVar3 + 720.0;
    }
    puVar1 = &DAT_00009224;
    if (fVar3 < 15.0) {
      ref_setSR_PARAM(local_14,0xe0);
      FUN_00009440(param_1,50000);
      *(undefined2 *)(&PTR_ATUII_DSTR_W_0000d82c)[(param_1 & 0xff) * 6] =
           *(undefined2 *)(&DAT_0000d830 + (param_1 & 0xff) * 0x18);
      puVar1 = (undefined4 *)FUN_00002064(local_14[0]);
    }
  }
  else {
    FUN_0000a8a4((&PTR_ATUII_DCNT8I_W_0000d81c)[(param_1 & 0xff) * 6],0);
    puVar1 = (undefined4 *)0x0;
    (&DAT_ffffa0dc)[iVar2] = 0;
    (&DAT_ffffa0dd)[iVar2] = 0;
  }
  return puVar1;
}


