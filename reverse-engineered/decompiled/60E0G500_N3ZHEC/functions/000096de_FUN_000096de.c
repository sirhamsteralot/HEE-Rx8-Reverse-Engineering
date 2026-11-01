/* ROM address: 0x000096de; body bytes: 32; decompiled */

/* Function candidate recovered from ROM pointer at 49c8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_000096de(void)

{
  int iVar1;
  
  iVar1 = FUN_00006010(2,&DAT_ffffa140);
  if (iVar1 == 0) {
    (*DAT_ffffa140)(&DAT_ffffa144);
  }
  FUN_00003d58();
  return;
}


