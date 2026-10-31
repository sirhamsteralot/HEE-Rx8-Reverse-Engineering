/* ROM address: 0x0000a2b6; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a2b6 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_calledLots(short param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 local_c;
  short sStack_8;
  
  sStack_8 = param_1;
  ref_setSR_PARAM(&local_c,0xe0);
  pcVar2 = &DAT_ffffa18b + sStack_8;
  if (*pcVar2 != -1) {
    *pcVar2 = *pcVar2 + '\x01';
  }
  uVar1 = FUN_00002064(local_c);
  return uVar1;
}


