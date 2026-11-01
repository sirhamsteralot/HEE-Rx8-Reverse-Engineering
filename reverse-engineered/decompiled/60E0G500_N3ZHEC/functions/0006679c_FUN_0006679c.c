/* ROM address: 0x0006679c; body bytes: 180; decompiled */

/* Function candidate recovered from ROM pointer at 5f300 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_0006679c(short param_1,char param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 local_30 [4];
  undefined *puStack_2c;
  undefined *puStack_28;
  undefined4 local_24;
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  DAT_ffffd8dc = 0;
  uVar2 = (uint)(param_1 != 0);
  if (uVar2 == 0) {
    puStack_2c = &DAT_ffffd880;
    uVar1 = FUN_00061d6a(0x80,2);
    local_30[0] = (undefined1)uVar1;
    puStack_28 = &DAT_ffffd8a8;
    DAT_ffffd8dc = FUN_00066f6c(3,&DAT_ffffd8a8,puStack_2c,uVar1);
    local_30[0] = 0x43;
    FUN_000688c8(3,local_30,1);
    FUN_000688c8(3,&DAT_ffffd8dc,1);
    FUN_000688c8(3,puStack_28,(uint)DAT_ffffd8dc << 1);
    iStack_20 = (uint)DAT_ffffd8dc * 2 + 2;
    local_24 = 3;
    uStack_1c = 8;
    uStack_18 = 0;
    uVar2 = FUN_000694fa();
  }
  else if (uVar2 == 1) {
    if (param_2 == '\x01') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    uVar2 = FUN_00066ece(3,0x12,uVar1);
  }
  return uVar2;
}


