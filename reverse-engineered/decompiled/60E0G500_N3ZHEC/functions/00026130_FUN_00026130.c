/* ROM address: 0x00026130; body bytes: 130; decompiled */

void FUN_00026130(char param_1)

{
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 auStack_1c [2];
  
  if (param_1 == '\x01') {
    FUN_00002054(auStack_1c,0xe0);
    FUN_00004bbc(0xfffff754,0x40,1);
    FUN_00002064(auStack_1c[0]);
    FUN_00002054(&uStack_20,0xe0);
    FUN_00004bbc(0xfffff754,0x20,1);
  }
  else {
    FUN_00002054(&uStack_24,0xe0);
    FUN_00004bbc(0xfffff754,0x20,0);
    FUN_00002064(uStack_24);
    FUN_00002054(&uStack_28,0xe0);
    FUN_00004bbc(0xfffff754,0x40,0);
    uStack_20 = uStack_28;
  }
  FUN_00002064(uStack_20);
  return;
}


