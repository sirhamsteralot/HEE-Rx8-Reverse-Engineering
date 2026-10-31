/* ROM address: 0x00065ff8; body bytes: 180; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000648e8 (180 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00065ff8(short param_1,char param_2)

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
  
  DAT_ffffd8a0 = 0;
  uVar2 = (uint)(param_1 != 0);
  if (uVar2 == 0) {
    puStack_2c = &DAT_ffffd844;
    uVar1 = FUN_000615c6(0x80,2);
    local_30[0] = (undefined1)uVar1;
    puStack_28 = &DAT_ffffd86c;
    DAT_ffffd8a0 = FUN_000667c8(3,&DAT_ffffd86c,puStack_2c,uVar1);
    local_30[0] = 0x43;
    ref_setupForUdsResponse_(3,local_30,1);
    ref_setupForUdsResponse_(3,&DAT_ffffd8a0,1);
    ref_setupForUdsResponse_(3,puStack_28,(uint)DAT_ffffd8a0 << 1);
    iStack_20 = (uint)DAT_ffffd8a0 * 2 + 2;
    local_24 = 3;
    uStack_1c = 8;
    uStack_18 = 0;
    uVar2 = FUN_00068d56();
  }
  else if (uVar2 == 1) {
    if (param_2 == '\x01') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    uVar2 = FUN_0006672a(3,0x12,uVar1);
  }
  return uVar2;
}


