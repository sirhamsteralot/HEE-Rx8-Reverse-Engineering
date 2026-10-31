/* ROM address: 0x00008dae; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00008dae (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_outputSpark1(undefined4 param_1,byte param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  iVar2 = (uint)param_2 * 8;
  *(undefined4 *)(&DAT_ffffa0d8 + iVar2) = param_1;
  (&DAT_ffffa0dd)[iVar2] = 0;
  (&DAT_ffffa0dc)[iVar2] = 2;
  FUN_000091c6((int)(char)param_2);
  ref_setSR(uVar1);
  return;
}


