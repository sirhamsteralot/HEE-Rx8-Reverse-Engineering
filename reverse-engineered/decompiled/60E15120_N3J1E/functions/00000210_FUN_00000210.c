/* ROM address: 0x00000210; body bytes: 70; decompiled */

undefined4 FUN_00000210(undefined4 param_1)

{
  ushort uVar1;
  
  uVar1 = HCAN0_RXPR_W;
  if ((uVar1 & 0x100) == 0) {
    return 0;
  }
  uVar1 = HCAN0_UMSR_W;
  if ((uVar1 & 0x100) != 0) {
    HCAN0_UMSR_W = 0x100;
    return 0xffffffff;
  }
  HCAN0_RXPR_W = 0x100;
  FUN_00000ace(8,0,param_1,&HCAN0_MD0_1__B);
  return 1;
}


