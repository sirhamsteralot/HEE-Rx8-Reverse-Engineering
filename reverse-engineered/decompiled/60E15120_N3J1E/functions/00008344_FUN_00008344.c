/* ROM address: 0x00008344; body bytes: 134; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00008344 (134 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00008344(byte param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  iVar3 = (uint)param_1 * 0x18;
  *(undefined4 *)(&DAT_ffffa004 + iVar3) = param_3;
  param_2 = param_2 - (int)(DAT_ffff9f98 * 65536.0);
  if (param_2 < -0x3c0000) {
    iVar2 = 0x2d00000;
  }
  else {
    if (param_2 < 0x2940000) goto LAB_0000839e;
    iVar2 = -0x2d00000;
  }
  param_2 = iVar2 + param_2;
LAB_0000839e:
  *(int *)(&DAT_ffffa008 + iVar3) = param_2;
  (&injector_channel_enable_flag_ffffa017)[iVar3] = 1;
  if (*(int *)(&DAT_ffffa008 + iVar3) < 0x230000) {
    FUN_00008814((int)(char)param_1);
    (&injector_channel_enable_flag_ffffa017)[iVar3] = 0;
  }
  ref_setSR(uVar1);
  return;
}


