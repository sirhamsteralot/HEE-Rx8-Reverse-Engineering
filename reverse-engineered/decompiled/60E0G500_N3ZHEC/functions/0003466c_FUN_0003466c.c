/* ROM address: 0x0003466c; body bytes: 298; decompiled */

undefined2 * FUN_0003466c(void)

{
  undefined2 *puVar1;
  float fVar2;
  
  if (DAT_ffffb5b8 < 7000.0) {
    if (DAT_ffffb5b8 < 6500.0) {
      DAT_ffffc125 = '\0';
    }
  }
  else {
    DAT_ffffc125 = '\x01';
  }
  if ((((((DAT_ffffa428 == '\0') || (DAT_ffffb5b8 < 2000.0)) || (7000.0 < DAT_ffffb5b8)) ||
       (((DAT_ffffc125 == '\x01' || (DAT_ffffaa10 < 255.0)) ||
        ((120.0 < DAT_ffffaa10 || ((DAT_ffffae54 < 255.0 || (150.0 < DAT_ffffae54)))))))) ||
      (DAT_ffffadbc <= 71.4)) ||
     (((DAT_ffffc11a < 0xfa || (DAT_ffffb5aa == '\x01')) || (DAT_ffffc11c < 0xfa)))) {
    DAT_ffffc103 = 0;
  }
  else {
    DAT_ffffc103 = 1;
  }
  if (DAT_ffffc103 == 0) {
    DAT_ffffc100 = 0;
  }
  fVar2 = DAT_ffffa370;
  if (DAT_ffffc100 == 0) {
    DAT_ffffc0c6 = '\0';
  }
  else if (2.5 <= DAT_ffffa370) {
    DAT_ffffc0c6 = FUN_00002478((int)DAT_ffffc0c6,1);
  }
  puVar1 = (undefined2 *)(uint)DAT_ffffc103;
  if (((puVar1 == (undefined2 *)&UNK_00000001) && (2.6 <= fVar2)) && (DAT_ffffc100 == 0)) {
    puVar1 = &DAT_0007a182;
    DAT_ffffc100 = 0x19;
  }
  return puVar1;
}


