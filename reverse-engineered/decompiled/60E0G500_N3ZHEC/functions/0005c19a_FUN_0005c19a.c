/* ROM address: 0x0005c19a; body bytes: 236; decompiled */

/* Function candidate recovered from ROM pointer at 5f33c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_0005c19a(short param_1,uint param_2)

{
  ushort uVar1;
  char cVar3;
  undefined4 uVar2;
  char local_18;
  char local_17;
  char cStack_16;
  
  uVar1 = DAT_ffffd3f0;
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 == 3) {
      if ((DAT_ffffd208 == '\x01') && (cVar3 = FUN_000565e2(0), cVar3 == '\0')) {
        FUN_00068928(0x28,&local_18,3);
        if (local_18 == '\x01') {
          if (((local_17 == '\0') && ((uVar1 & 0xfffc) != 0)) ||
             ((local_17 == '\x01' && ((uVar1 & 0xfffc) != 0)))) {
            if (cStack_16 == '\x01') {
              FUN_0005c36a((int)local_17);
              uVar2 = FUN_0005c392();
            }
            else {
              uVar2 = FUN_00055112(0x28,0x31);
            }
          }
          else {
            uVar2 = FUN_00055112(0x28,0x31);
          }
        }
        else {
          uVar2 = FUN_00055112(0x28,0x12);
        }
      }
      else {
        uVar2 = FUN_00055112(0x28,0x22);
      }
    }
    else {
      uVar2 = FUN_00055112(0x28,0x12);
    }
    param_2 = FUN_000550ca(0x28,uVar2);
  }
  else if (param_2 == 0) {
    param_2 = FUN_000550ee(0x28);
  }
  return param_2;
}


