/* ROM address: 0x00043c50; body bytes: 110; decompiled */

undefined4 FUN_00043c50(void)

{
  char cVar2;
  undefined4 uVar1;
  undefined4 extraout_fr0;
  float fVar3;
  
  fVar3 = DAT_ffffcaa0;
  cVar2 = FUN_00002440(DAT_ffffcaa0,0,0x3727c5ac);
  if (cVar2 != '\0') {
    DAT_ffffca9c = DAT_ffffb5b8 / fVar3;
  }
  if ((DAT_ffffcabf == '\0') || (DAT_ffffb5aa == '\x01')) {
    DAT_ffffca98 = FUN_00002068(DAT_ffffca9c,&DAT_0006bbb4);
    uVar1 = FUN_00002068(DAT_ffffca9c,&DAT_0006bba0);
    DAT_ffffca94 = extraout_fr0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


