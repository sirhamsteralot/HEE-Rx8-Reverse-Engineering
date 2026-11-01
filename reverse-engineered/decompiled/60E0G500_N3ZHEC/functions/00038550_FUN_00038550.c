/* ROM address: 0x00038550; body bytes: 38; decompiled */

void FUN_00038550(void)

{
  undefined4 uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc29a = '\0';
  }
  if (DAT_ffffc29a == '\0') {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  FUN_000604dc(0x4d,uVar1);
  return;
}


