/* ROM address: 0x000691e8; body bytes: 66; decompiled */

void FUN_000691e8(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_000693fc(5);
  DAT_ffffde2b = FUN_00002478((int)DAT_ffffde2b,1);
  if (DAT_ffffde34 == '\x01') {
    uVar2 = 5;
    DAT_ffffde27 = 2;
    uVar1 = 6;
  }
  else {
    uVar2 = 0x96;
    uVar1 = 5;
    DAT_ffffde2b = 0;
    DAT_ffffde27 = 4;
  }
  FUN_0006936a(uVar1,uVar2);
  return;
}


