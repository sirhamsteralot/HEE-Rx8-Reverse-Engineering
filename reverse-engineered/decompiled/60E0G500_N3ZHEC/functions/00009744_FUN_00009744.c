/* ROM address: 0x00009744; body bytes: 274; decompiled */

void FUN_00009744(char param_1,undefined4 *param_2,byte param_3)

{
  undefined2 *puVar1;
  uint uVar2;
  
  if (param_1 == '\0') {
    FUN_0000ca9c(0);
    FUN_0000cb42(0);
    puVar1 = (undefined2 *)FUN_0000cefe(0,&DAT_ffffe402);
    *puVar1 = 0x803e;
    FUN_0000cb9c(0);
    FUN_0000cbf8(0);
    FUN_0000cc1e(0);
  }
  else {
    FUN_0000ca9c(1);
    FUN_0000cb42(1);
    puVar1 = (undefined2 *)FUN_0000cefe(1,&DAT_ffffe402);
    *puVar1 = 0x803e;
    FUN_0000cb9c(1,0);
    FUN_0000cbf8(1,0);
    FUN_0000cc1e(1,0);
  }
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      FUN_0000cacc((int)*(char *)((int)param_2 + 5),(int)*(char *)(param_2 + 1),
                   (int)*(char *)((int)param_2 + 6),(int)*(char *)((int)param_2 + 7),*param_2,
                   (int)*(char *)(param_2 + 3));
      uVar2 = uVar2 + 1;
      param_2 = param_2 + 4;
    } while (uVar2 < param_3);
  }
  if (param_1 == '\0') {
    FUN_0000cab4(0);
    puVar1 = (undefined2 *)FUN_0000cefe(0,&DAT_ffffe416);
    *puVar1 = 0xfcfe;
    FUN_0000cc46(0,0);
    return;
  }
  FUN_0000cab4(1);
  puVar1 = (undefined2 *)FUN_0000cefe(1,&DAT_ffffe416);
  *puVar1 = 0xfcfe;
  FUN_0000cc46(1,0);
  return;
}


