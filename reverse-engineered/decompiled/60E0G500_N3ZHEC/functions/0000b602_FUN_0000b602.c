/* ROM address: 0x0000b602; body bytes: 104; decompiled */

void FUN_0000b602(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x90);
  if (DAT_ffffa323 < 200) {
    DAT_ffffa323 = DAT_ffffa323 + 1;
  }
  else {
    DAT_ffffa229 = 1;
  }
  FUN_00003934(uVar1);
  uVar1 = FUN_00003920(0x90);
  if (DAT_ffffa322 == '\x01') {
    if (DAT_ffffa321 < 4) {
      DAT_ffffa321 = DAT_ffffa321 + 1;
    }
    else {
      FUN_0000bd28();
    }
  }
  FUN_00003934(uVar1);
  return;
}


