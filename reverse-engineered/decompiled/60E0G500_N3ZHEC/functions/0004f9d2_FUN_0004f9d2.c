/* ROM address: 0x0004f9d2; body bytes: 58; decompiled */

uint FUN_0004f9d2(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = FUN_0003eb72(0,&DAT_ffff86d0);
  uVar1 = FUN_00002440(uVar2,uVar3,0x36b33333);
  if (((uVar1 & 0xff) != 0) && (uVar1 = (uint)DAT_ffffd0e4, uVar1 == 1)) {
    DAT_ffffd006 = 1;
  }
  return uVar1;
}


