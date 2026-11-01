/* ROM address: 0x00003610; body bytes: 138; decompiled */

void FUN_00003610(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  uint in_sr;
  
  if ((param_3 & 0x2000) == 0) {
    if ((param_3 & 0x4000) == 0) {
      if ((param_3 & (uint)(undefined *)0x8000) == 0) {
        if ((param_3 & (uint)&PTR_DAT_00020000) == 0) {
          if ((param_3 & (uint)&DAT_00010000) == 0) {
            if (((param_3 & 0xf) == 0) && ((in_sr & 0xf0) == 0)) {
              if ((param_3 & 0xf00) == 0) {
                if ((param_3 & 0x80000000) == 0) {
                  uVar1 = 2;
                }
                else {
                  uVar1 = 1;
                }
              }
              else {
                uVar1 = 0;
              }
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


