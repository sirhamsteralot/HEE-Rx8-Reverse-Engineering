/* ROM address: 0x00053008; body bytes: 44; decompiled */

uint FUN_00053008(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (uint)DAT_ffffd079;
  if (uVar1 == 1) {
    uVar2 = FUN_00003920(0x10);
    DAT_ffffd148 = 0;
    uVar1 = FUN_00003934(uVar2);
  }
  return uVar1;
}


