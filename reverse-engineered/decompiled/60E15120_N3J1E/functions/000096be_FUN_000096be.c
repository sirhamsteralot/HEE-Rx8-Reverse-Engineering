/* ROM address: 0x000096be; body bytes: 32; decompiled */

/* Function candidate recovered from ROM pointer at 49b8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_000096be(void)

{
  int iVar1;
  
  iVar1 = FUN_00006010(1,&DAT_ffffa12c);
  if (iVar1 == 0) {
    (*DAT_ffffa12c)(&DAT_ffffa130);
  }
  ref_taskEndRoutine_();
  return;
}


