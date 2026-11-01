/* ROM address: 0x0000a936; body bytes: 286; decompiled */

/* Function candidate recovered from ROM pointer at 653c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined2 * FUN_0000a936(void)

{
  undefined2 *puVar1;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 auStack_24 [2];
  
  DAT_ffffa1be = DAT_ffffa1be + 1;
  if ((undefined2 *)(uint)DAT_ffffa1be < &UNK_00000060) {
    puVar1 = (undefined2 *)(uint)DAT_ffffa1c0;
    if ((puVar1 <= (undefined2 *)(uint)DAT_ffffa1be) &&
       (puVar1 = (undefined2 *)(uint)DAT_ffffa1c8, puVar1 == (undefined2 *)&UNK_00000001)) {
      DAT_ffffa1c8 = 0;
      FUN_00002054(&uStack_2c,0xe0);
      FUN_00004bbc(0xfffff75e,0x20,1);
      puVar1 = (undefined2 *)FUN_00002064(uStack_2c);
    }
    if ((DAT_ffffa1c2 <= DAT_ffffa1be) &&
       (puVar1 = (undefined2 *)(uint)DAT_ffffa1c9, puVar1 == (undefined2 *)&UNK_00000001)) {
      DAT_ffffa1c9 = 0;
      FUN_00002054(&local_30,0xe0);
      FUN_00004bbc(0xfffff75e,0x100,0);
      puVar1 = (undefined2 *)FUN_00002064(local_30);
    }
  }
  else {
    DAT_ffffa1be = 0;
    DAT_ffffa1c0 = DAT_ffffa1c4;
    DAT_ffffa1c2 = DAT_ffffa1c6;
    if (DAT_ffffa1c4 != 0) {
      FUN_00002054(auStack_24,0xe0);
      FUN_00004bbc(0xfffff75e,0x20,0);
      FUN_00002064(auStack_24[0]);
      DAT_ffffa1c8 = 1;
    }
    puVar1 = &DAT_ffffa1c2;
    if (DAT_ffffa1c2 != 0) {
      FUN_00002054(&uStack_28,0xe0);
      FUN_00004bbc(0xfffff75e,0x100,1);
      puVar1 = (undefined2 *)FUN_00002064(uStack_28);
      DAT_ffffa1c9 = 1;
    }
  }
  if (DAT_ffffa1be == 4) {
    puVar1 = (undefined2 *)FUN_0000aac4();
  }
  return puVar1;
}


