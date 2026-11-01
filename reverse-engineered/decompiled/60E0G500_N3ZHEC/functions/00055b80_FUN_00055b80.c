/* ROM address: 0x00055b80; body bytes: 78; decompiled */

undefined4 diag_read_calc_load_pct(void)

{
  char cVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  
  uVar2 = 0;
  fVar3 = DAT_ffffc12c;
  fVar4 = DAT_ffffc130;
  cVar1 = FUN_00002440(DAT_ffffc130,0,0x3727c5ac);
  if (cVar1 == '\0') {
    uVar2 = 0xff;
  }
  else {
    uVar2 = FUN_000024d0((fVar3 * 100.0) / fVar4,0x3ec8c8c8,uVar2);
  }
  return uVar2;
}


