/* ROM address: 0x00056f8c; body bytes: 110; decompiled */

/* Function candidate recovered from ROM pointer at 5f390 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined * FUN_00056f8c(short param_1,uint param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined1 local_c;
  undefined1 uStack_b;
  
  puVar2 = (undefined *)(param_2 & 0xff);
  if (puVar2 == &UNK_00000001) {
    if (param_1 == 2) {
      FUN_00068928(0x22,&local_c,2);
      DAT_ffffd226 = CONCAT11(local_c,uStack_b);
      DAT_ffffd224 = 0;
      puVar2 = &DAT_ffffd228;
      DAT_ffffd228 = 1;
    }
    else {
      uVar1 = FUN_00055112(0x22,0x12);
      puVar2 = (undefined *)FUN_000550ca(0x22,uVar1);
    }
  }
  else if (puVar2 == (undefined *)0x0) {
    puVar2 = (undefined *)FUN_000550ee(0x22);
  }
  return puVar2;
}


