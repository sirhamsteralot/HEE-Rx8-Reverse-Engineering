/* ROM address: 0x00065198; body bytes: 230; decompiled */

/* Function candidate recovered from ROM pointer at 684d8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_00065198(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_0006359c(1);
  uVar2 = FUN_00065d40(uVar1);
  uVar2 = uVar2 & 0xff;
  if (uVar2 == 0x60) {
    FUN_00062b44(1);
    FUN_00062bc4(8);
    FUN_0006357c(0x50);
    FUN_000638ae(7);
    FUN_000635ee(0);
    FUN_00063660(3);
    FUN_000636d2(0x28);
    FUN_00063744(0x50);
    FUN_000637ca(0);
    FUN_0006383c(0);
    FUN_0006305c();
    FUN_00062e0c();
    FUN_00067f04();
    FUN_00067de0(0);
    FUN_00067e6c(0);
    FUN_00063098();
    FUN_00060e62();
    uVar2 = FUN_00062f44();
    return uVar2;
  }
  if (uVar2 == 0x70) {
    FUN_00062b44(1);
    FUN_00062bc4(8);
    FUN_0006357c(0xc1);
    FUN_000635ee(0);
    FUN_00063660(3);
    FUN_00063744(0x50);
    FUN_000637ca(0);
    FUN_0006383c(0);
    FUN_0006305c();
    FUN_00062e0c();
    FUN_00067f04();
    FUN_00063098();
    uVar2 = FUN_00062f44();
    return uVar2;
  }
  return uVar2;
}


