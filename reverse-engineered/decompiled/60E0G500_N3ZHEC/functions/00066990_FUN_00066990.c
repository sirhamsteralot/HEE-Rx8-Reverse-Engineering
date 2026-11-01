/* ROM address: 0x00066990; body bytes: 180; decompiled */

/* Function candidate recovered from ROM pointer at 5f324 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint obd_mode07_pending_dtc(short param_1,char param_2)

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
  
  DAT_ffffd93c = 0;
  uVar2 = (uint)(param_1 != 0);
  if (uVar2 == 0) {
    puStack_2c = &DAT_ffffd8e0;
    uVar1 = FUN_000624cc(1,2);
    local_30[0] = (undefined1)uVar1;
    puStack_28 = &DAT_ffffd908;
    DAT_ffffd93c = FUN_00066f6c(7,&DAT_ffffd908,puStack_2c,uVar1);
    local_30[0] = 0x47;
    FUN_000688c8(7,local_30,1);
    FUN_000688c8(7,&DAT_ffffd93c,1);
    FUN_000688c8(7,puStack_28,(uint)DAT_ffffd93c << 1);
    iStack_20 = (uint)DAT_ffffd93c * 2 + 2;
    local_24 = 7;
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
    uVar2 = FUN_00066ece(7,0x12,uVar1);
  }
  return uVar2;
}


