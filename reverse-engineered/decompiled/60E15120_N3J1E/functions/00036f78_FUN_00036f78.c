/* ROM address: 0x00036f78; body bytes: 134; decompiled */

/* Function candidate recovered from ROM pointer at 5f0d4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined4 FUN_00036f78(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  byte local_10 [8];
  
  uVar2 = 0;
  iVar3 = 0;
  ref_udsServiceResponse(0xb1,local_10,1);
  if ((inferred_ram_c1d2_ffffc1d2_ffffc1d2 == -0x56) &&
     ((cVar1 = FUN_00055e3e(0), cVar1 == '\0' || (cVar1 = FUN_00055e3e(2), cVar1 == '\0')))) {
    if ((local_10[0] < 8) || (0x3f < local_10[0])) {
      iVar3 = 0x31;
    }
    else {
      inferred_ram_c1d4_ffffc1d4_ffffc1d4 = local_10[0];
      DAT_ffffc253 = 1;
    }
  }
  else {
    iVar3 = 0x22;
  }
  if (iVar3 != 0) {
    uVar2 = ref_udsErrorResponse(0xb1,iVar3);
  }
  return uVar2;
}


