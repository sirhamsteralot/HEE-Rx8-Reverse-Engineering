/* ROM address: 0x00058208; body bytes: 426; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00058272) */
/* Function candidate recovered from ROM pointer at 5f360 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_00058208(short param_1,uint param_2)

{
  uint uVar1;
  char cVar3;
  byte bVar4;
  uint uVar2;
  undefined4 uVar5;
  byte local_30 [4];
  short sStack_2c;
  char cStack_28;
  undefined1 local_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 auStack_20 [8];
  
  param_2 = param_2 & 0xff;
  sStack_2c = param_1;
  if (param_2 != 1) {
    if (param_2 != 0) {
      return param_2;
    }
    uVar2 = FUN_000550ee(0x27);
    return uVar2;
  }
  FUN_00068928(0x27,local_30,1);
  cStack_28 = FUN_000565ce();
  uVar2 = FUN_0005664e();
  if (sStack_2c == 0) {
    uVar5 = 0x12;
  }
  else {
    if (local_30[0] != 0) {
      if ((local_30[0] & 1) == 1) {
        if (sStack_2c == 1) {
          FUN_00056702(3);
          uVar1 = FUN_000565fa((int)(char)local_30[0]);
          if ((uVar1 & 0xff) == 3) {
            uVar5 = FUN_00055112(0x27,0x31);
          }
          else {
            cVar3 = FUN_00056690((int)cStack_28,uVar2,uVar1);
            if (cVar3 == '\0') {
              if ((uVar2 & 0xff) == (uVar1 & 0xff)) {
                uStack_22 = 0;
                uStack_23 = 0;
                local_24 = 0;
              }
              else {
                FUN_00056702(uVar1);
                FUN_00056828(&local_24);
              }
              uVar5 = FUN_000583b2((int)(char)local_30[0],&local_24,3);
            }
            else {
              uVar5 = FUN_00055112(0x27,0x31);
            }
          }
        }
        else {
          uVar5 = FUN_00055112(0x27,0x12);
        }
      }
      else if (sStack_2c == 4) {
        uVar2 = FUN_00056828(&local_24);
        FUN_00056702(3);
        if ((uVar2 & 0xff) == 3) {
          uVar5 = FUN_00055112(0x27,0x22);
        }
        else {
          bVar4 = FUN_000566f2(uVar2);
          if (bVar4 == local_30[0]) {
            FUN_00068928(0x27,auStack_20,3);
            cVar3 = FUN_00056842(uVar2,&local_24,auStack_20);
            if (cVar3 == '\0') {
              FUN_00056488(uVar2);
              uVar5 = FUN_000583b2((int)(char)local_30[0],auStack_20,0);
            }
            else {
              uVar5 = FUN_00055112(0x27,0x35);
            }
          }
          else {
            uVar5 = FUN_00055112(0x27,0x22);
          }
        }
      }
      else {
        uVar5 = FUN_00055112(0x27,0x12);
      }
      goto LAB_0005838a;
    }
    uVar5 = 0x31;
  }
  uVar5 = FUN_00055112(0x27,uVar5);
LAB_0005838a:
  uVar2 = FUN_000550ca(0x27,uVar5);
  return uVar2;
}


