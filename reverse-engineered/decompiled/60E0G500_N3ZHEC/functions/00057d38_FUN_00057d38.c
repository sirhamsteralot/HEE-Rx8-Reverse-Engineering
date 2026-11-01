/* ROM address: 0x00057d38; body bytes: 288; decompiled */

/* Function candidate recovered from ROM pointer at 5fccc and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1710_sensor_snapshot_7byte(undefined4 param_1)

{
  char cVar2;
  uint uVar1;
  byte bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar7 = 0;
  uVar4 = FUN_0003eb72(0,&DAT_ffff9178);
  uVar5 = 0x3f800000;
  uVar4 = FUN_000024d0(uVar4,0x3f800000,uVar7);
  diag_append_u8(param_1,uVar4);
  uVar4 = FUN_0003eb72(uVar7,&DAT_ffff9180);
  uVar4 = FUN_000024d0(uVar4,uVar5,0xc2200000);
  diag_append_u8(param_1,uVar4);
  uVar4 = FUN_0003eb72(uVar7,&DAT_ffff9188);
  uVar5 = 0xc1c80000;
  uVar6 = 0x3e480000;
  uVar4 = FUN_000024d0(uVar4,0x3e480000,0xc1c80000);
  diag_append_u8(param_1,uVar4);
  uVar4 = FUN_0003eb72(uVar7,&DAT_ffff9190);
  uVar4 = FUN_000024d0(uVar4,uVar6,uVar5);
  diag_append_u8(param_1,uVar4);
  cVar2 = FUN_0003eaa4(&DAT_ffff919c,1);
  bVar3 = cVar2 == '\x01';
  cVar2 = FUN_0003eaa4(&DAT_ffff919e,1);
  if (cVar2 == '\x01') {
    bVar3 = bVar3 | 2;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff91a0,0);
  if (cVar2 == '\x01') {
    bVar3 = bVar3 | 4;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff91a2,0);
  if (cVar2 == '\x01') {
    bVar3 = bVar3 | 8;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff91a4,0);
  if (cVar2 == '\x01') {
    bVar3 = bVar3 | 0x10;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff91a6,0);
  if (cVar2 == '\x01') {
    bVar3 = bVar3 | 0x20;
  }
  uVar4 = diag22_subpid_supported_mask(bVar3,5);
  diag_append_u8(param_1,uVar4);
  uVar1 = FUN_0003eaa4(&DAT_ffff9198,0xff);
  diag_append_u8(param_1,uVar1 & (int)DAT_ffffd3c6);
  uVar1 = FUN_0003eaa4(&DAT_ffff919a,0xff);
  diag_append_u8(param_1,uVar1 & (int)DAT_ffffd3c7);
  return;
}


