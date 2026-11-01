/* ROM address: 0x00016798; body bytes: 68; decompiled */

undefined4 FUN_00016798(void)

{
  undefined4 uVar1;
  float extraout_fr0;
  float extraout_fr0_00;
  float fVar2;
  
  if (DAT_ffffb5a4 == '\x01') {
    uVar1 = FUN_00002068(&DAT_00069c14);
    fVar2 = extraout_fr0;
  }
  else {
    uVar1 = FUN_000020dc(DAT_ffffaa14,DAT_ffffaa1c,&DAT_00069c28);
    fVar2 = extraout_fr0_00;
  }
  if (fVar2 < DAT_ffffa8d8 + 20.0) {
    DAT_ffffa8d4 = fVar2;
  }
  DAT_ffffa8d8 = DAT_ffffa8d4;
  return uVar1;
}


