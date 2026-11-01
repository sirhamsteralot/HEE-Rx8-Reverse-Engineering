/* ROM address: 0x00068f1a; body bytes: 78; decompiled */

void FUN_00068f1a(char param_1)

{
  if (param_1 == '\0') {
    DAT_ffffde0c = 0;
    FUN_00068f68();
  }
  else if (param_1 == '\x10') {
    DAT_ffffde0c = 0x10;
    FUN_00068f8c();
  }
  else if (param_1 == ' ') {
    DAT_ffffde0c = 0x20;
    FUN_00068fca();
  }
  else if (param_1 == '0') {
    DAT_ffffde0c = 0x30;
    FUN_0006900c();
  }
  FUN_000099b0(&DAT_0004e7b8);
  return;
}


