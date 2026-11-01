/* ROM address: 0x00034be4; body bytes: 108; decompiled */

undefined4 FUN_00034be4(void)

{
  undefined4 uVar1;
  undefined4 extraout_fr0;
  float fVar2;
  
  fVar2 = DAT_ffffc1c8;
  DAT_ffffc14c = (float)FUN_00002068(DAT_ffffc1c8,&DAT_0006b444);
  DAT_ffffc150 = (float)FUN_00002068(DAT_ffffc12c,&DAT_0006b430);
  if (fVar2 < 0.0) {
    DAT_ffffc148 = DAT_ffffc14c * 1.0 * DAT_ffffc150;
  }
  else {
    DAT_ffffc148 = 0.0;
  }
  if (DAT_ffffa42c == '\x01') {
    DAT_ffffc154 = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_000020dc(DAT_ffffb5b8,DAT_ffffaa10,&PTR_DAT_0006b480);
    DAT_ffffc154 = extraout_fr0;
  }
  return uVar1;
}


