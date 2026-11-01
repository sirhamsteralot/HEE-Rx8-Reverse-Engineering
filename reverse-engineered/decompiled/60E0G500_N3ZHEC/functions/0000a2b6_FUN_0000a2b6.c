/* ROM address: 0x0000a2b6; body bytes: 54; decompiled */

undefined4 FUN_0000a2b6(short param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 local_c;
  short sStack_8;
  
  sStack_8 = param_1;
  FUN_00002054(&local_c,0xe0);
  pcVar2 = &DAT_ffffa18b + sStack_8;
  if (*pcVar2 != -1) {
    *pcVar2 = *pcVar2 + '\x01';
  }
  uVar1 = FUN_00002064(local_c);
  return uVar1;
}


