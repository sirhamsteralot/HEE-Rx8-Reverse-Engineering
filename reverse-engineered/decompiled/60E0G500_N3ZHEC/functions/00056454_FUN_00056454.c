/* ROM address: 0x00056454; body bytes: 52; decompiled */

void FUN_00056454(char param_1)

{
  undefined4 uVar1;
  
  DAT_ffffd20b = param_1;
  FUN_00056488(0);
  DAT_ffffd20d = FUN_00056ac4((int)param_1);
  DAT_ffffde5c = DAT_ffffd20d;
  FUN_0005c6f4();
  if (DAT_ffffd20b == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = 3;
  }
  FUN_00056490(uVar1);
  return;
}


