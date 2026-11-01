/* ROM address: 0x000138f8; body bytes: 62; decompiled */

uint FUN_000138f8(void)

{
  uint uVar1;
  float fVar2;
  undefined4 uVar3;
  
  if (DAT_ffffa74a == 1) {
    fVar2 = (float)FUN_0003eb72(0,&DAT_ffff8038);
    fVar2 = rx8_first_order_filter(DAT_ffffa734,fVar2,0.0039,1e-05);
    uVar3 = FUN_00013bd4(fVar2);
    uVar1 = FUN_0003ec20(uVar3,&DAT_ffff8038);
    return uVar1;
  }
  return (uint)DAT_ffffa74a;
}


