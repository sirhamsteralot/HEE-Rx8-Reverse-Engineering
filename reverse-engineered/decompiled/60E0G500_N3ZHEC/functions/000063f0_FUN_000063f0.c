/* ROM address: 0x000063f0; body bytes: 158; decompiled */

/* Function candidate recovered from ROM pointer at 4a08 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined4 FUN_000063f0(void)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  FUN_0000a3ac();
  FUN_00006a4c();
  FUN_00007438();
  FUN_0000acfc();
  FUN_0000b602();
  FUN_000114fc();
  DAT_ffff9f52 = DAT_ffff9f52 + 1;
  FUN_00002054(local_8,0xe0);
  if (DAT_ffff9f52 < DAT_ffff9f54) {
    if (DAT_ffff9f58 <= DAT_ffff9f52) {
      FUN_00004bbc(0xfffff746,0x10,0);
    }
  }
  else {
    DAT_ffff9f52 = 0;
    DAT_ffff9f58 = DAT_ffff9f5a;
    DAT_ffff9f54 = DAT_ffff9f56;
    if ((DAT_ffff9f5c == '\0') && (DAT_ffff9f5a != 0)) {
      FUN_00004bbc(0xfffff746,0x10,1);
    }
  }
  FUN_00002064(local_8[0]);
  FUN_0000a936();
  uVar1 = FUN_00003d58();
  return uVar1;
}


