/* ROM address: 0x00000256; body bytes: 110; decompiled */

void FUN_00000256(char param_1,byte param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  uint uVar3;
  byte bVar4;
  
  bVar4 = 0;
  if (param_2 != 0) {
    do {
      uVar3 = (uint)bVar4;
      uVar1 = *param_3;
      param_3 = param_3 + 1;
      bVar4 = bVar4 + 1;
      (&DAT_ffffdfae)[uVar3] = uVar1;
    } while (bVar4 < param_2);
  }
  DAT_ffffdfad = param_1 + param_2;
  if ((param_1 == -0x20) || (param_1 == -0x28)) {
    DAT_ffffdfac = 0;
  }
  else {
    DAT_ffffdfac = 0x7a;
  }
  do {
    uVar2 = HCAN0_TXPR_W;
  } while ((uVar2 & 0x200) != 0);
  HCAN0_TXACK_W = 0x200;
  FUN_00000ae8(8,0,&DAT_ffffdfac,&HCAN0_MD1_1__B);
  HCAN0_TXPR_W = 0x200;
  return;
}


