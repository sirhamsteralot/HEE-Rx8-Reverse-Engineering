/* ROM address: 0x000661ec; body bytes: 180; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064adc (180 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000661ec(short param_1,char param_2)

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
  
  DAT_ffffd900 = 0;
  uVar2 = (uint)(param_1 != 0);
  if (uVar2 == 0) {
    puStack_2c = &DAT_ffffd8a4;
    uVar1 = FUN_00061d28(1,2);
    local_30[0] = (undefined1)uVar1;
    puStack_28 = &DAT_ffffd8cc;
    DAT_ffffd900 = FUN_000667c8(7,&DAT_ffffd8cc,puStack_2c,uVar1);
    local_30[0] = 0x47;
    ref_setupForUdsResponse_(7,local_30,1);
    ref_setupForUdsResponse_(7,&DAT_ffffd900,1);
    ref_setupForUdsResponse_(7,puStack_28,(uint)DAT_ffffd900 << 1);
    iStack_20 = (uint)DAT_ffffd900 * 2 + 2;
    local_24 = 7;
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
    uVar2 = FUN_0006672a(7,0x12,uVar1);
  }
  return uVar2;
}


