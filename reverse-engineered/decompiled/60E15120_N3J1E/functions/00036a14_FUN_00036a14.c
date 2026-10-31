/* ROM address: 0x00036a14; body bytes: 146; decompiled */

/* Function candidate recovered from ROM pointer at 5f0a4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined4 FUN_00036a14(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char local_10 [8];
  
  uVar2 = 0;
  iVar3 = 0;
  ref_udsServiceResponse(0xb1,local_10,1);
  if ((DAT_ffffc1d2 == -0x56) &&
     ((cVar1 = FUN_00055e3e(0), cVar1 == '\0' || (cVar1 = FUN_00055e3e(2), cVar1 == '\0')))) {
    if (local_10[0] == '\0') {
      DAT_ffffc1d3 = DAT_ffffc1d3 & 0x7f;
      DAT_ffffc24d = 1;
    }
    else if (local_10[0] == '\x01') {
      DAT_ffffc1d3 = DAT_ffffc1d3 | 0x80;
      DAT_ffffc24d = 1;
    }
    else {
      iVar3 = 0x31;
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


