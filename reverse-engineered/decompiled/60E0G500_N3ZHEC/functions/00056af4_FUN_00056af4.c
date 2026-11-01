/* ROM address: 0x00056af4; body bytes: 140; decompiled */

/* Function candidate recovered from ROM pointer at 5f89c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined4 FUN_00056af4(void)

{
  char cVar2;
  undefined4 uVar1;
  char local_14 [8];
  
  cVar2 = FUN_000565e2(1);
  if (cVar2 == '\0') {
    cVar2 = FUN_00056678(1);
    if (cVar2 == '\0') {
      cVar2 = FUN_00056bcc();
      if (cVar2 == '\0') {
        FUN_00068928(0xb1,local_14,1);
        if (local_14[0] == '\0') {
          uVar1 = FUN_00056c50();
          FUN_00056b82(3);
        }
        else {
          uVar1 = FUN_00055112(0xb1,0x31);
        }
      }
      else {
        uVar1 = FUN_00055112(0xb1);
      }
    }
    else {
      uVar1 = FUN_00055112(0xb1,0x33);
    }
  }
  else {
    uVar1 = FUN_00055112(0xb1,0x22);
  }
  return uVar1;
}


