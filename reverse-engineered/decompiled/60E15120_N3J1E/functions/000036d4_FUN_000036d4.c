/* ROM address: 0x000036d4; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000036d4 (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000036d4(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  
  if ((param_3 & 0x2000) == 0) {
    if ((param_3 & 0x4000) == 0) {
      if ((param_3 & 0x8000) == 0) {
        if ((param_3 & 0x20000) == 0) {
          if ((param_3 & (uint)&DAT_00010000) == 0) {
            if (((param_3 & 0xf) == 0) && ((param_4 & 0xf0) == 0)) {
              uVar1 = 2;
            }
            else {
              uVar1 = 3;
            }
          }
          else {
            uVar1 = 8;
          }
        }
        else {
          uVar1 = 7;
        }
      }
      else {
        uVar1 = 6;
      }
    }
    else {
      uVar1 = 5;
    }
    DAT_ffff7640 = DAT_ffff7640 | 0x2000;
    (*(code *)0x0)(param_1,param_2,uVar1);
    DAT_ffff7640 = DAT_ffff7640 & 0xffffdfff;
  }
  return;
}


