/* ROM address: 0x0001de76; body bytes: 180; decompiled */

uint FUN_0001de76(void)

{
  ushort uVar2;
  uint uVar1;
  undefined4 uVar3;
  
  if (DAT_ffffcb38 == '\0') {
    uVar3 = DAT_ffffb5b8;
    uVar2 = FUN_000020ac(DAT_ffffb5b8,&PTR_DAT_00069f60);
    DAT_ffffb08e = uVar2 & 0xff;
    DAT_ffffb06c = FUN_000020dc(DAT_ffffaa88,uVar3,&DAT_0006a0fc);
  }
  else {
    uVar3 = DAT_ffffb5b8;
    uVar2 = FUN_000020ac(DAT_ffffb5b8,&PTR_DAT_00069f6c);
    DAT_ffffb08e = uVar2 & 0xff;
    DAT_ffffb06c = FUN_000020dc(DAT_ffffaa88,uVar3,&DAT_0006a118);
  }
  uVar1 = 1;
  if ((DAT_ffffc770 == '\x01') ||
     ((((uVar1 = (uint)DAT_ffffae97, uVar1 == 1 && (150.0 <= DAT_ffffaa10)) &&
       (uVar1 = (uint)DAT_ffffad9c, uVar1 == 1)) && (uVar1 = (uint)DAT_ffffae98, uVar1 == 0)))) {
    DAT_ffffae99 = 1;
  }
  else {
    DAT_ffffae99 = 0;
  }
  return uVar1;
}


