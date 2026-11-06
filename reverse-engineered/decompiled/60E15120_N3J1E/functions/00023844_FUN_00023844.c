/* ROM address: 0x00023844; body bytes: 1562; decompiled */

void e2ram_block_decode(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = 0x3cfa0000;
  DAT_ffffb4b0 = rx8_decode_u16_affine(0x3cfa0000,0,(int)e2ram_payload_raw_ffffb47a);
  DAT_ffffb4b4 = rx8_decode_u16_affine(uVar2,uVar3,(int)DAT_ffffb47c);
  DAT_ffffb4cc = DAT_ffffb47e;
  DAT_ffffb4ce = DAT_ffffb480;
  DAT_ffffb4d0 = DAT_ffffb482;
  DAT_ffffb4d2 = DAT_ffffb484;
  DAT_ffffb4d4 = DAT_ffffb486;
  DAT_ffffb4b8 = rx8_decode_u8_affine(0x3da00000,uVar3,(int)DAT_ffffb488);
  if (DAT_ffffb489 < 0x80) {
    DAT_ffffb4bc = (float)rx8_decode_u8_affine(0x3f480000,uVar3);
  }
  else {
    fVar1 = (float)rx8_decode_u8_affine
                             (0x3f480000,uVar3,~(int)(char)DAT_ffffb489 + 1);
    DAT_ffffb4bc = -fVar1;
  }
  FUN_00024b00((int)DAT_ffffb48a,&DAT_ffffb52d,&DAT_ffffb526);
  stored_dtc_flag_bits_ffffb4ec = (DAT_ffffb526 & 1) == 1;
  DAT_ffffb4ed = (DAT_ffffb526 & 2) != 0;
  DAT_ffffb4ee = (DAT_ffffb526 & 4) != 0;
  DAT_ffffb4ef = (DAT_ffffb526 & 8) != 0;
  DAT_ffffb4f0 = (DAT_ffffb526 & 0x10) != 0;
  DAT_ffffb4f1 = (DAT_ffffb526 & 0x20) != 0;
  DAT_ffffb4f2 = (DAT_ffffb526 & 0x40) != 0;
  FUN_00024b00((int)DAT_ffffb48b,&DAT_ffffb52e,&DAT_ffffb527);
  DAT_ffffb4f3 = (DAT_ffffb527 & 1) == 1;
  DAT_ffffb4f4 = (DAT_ffffb527 & 2) != 0;
  DAT_ffffb4f5 = (DAT_ffffb527 & 0x40) != 0;
  DAT_ffffb4f6 = ((int)(char)DAT_ffffb527 & 0x80U) != 0;
  FUN_00024b00((int)DAT_ffffb48c,&DAT_ffffb52f,&DAT_ffffb528);
  DAT_ffffb4f7 = (DAT_ffffb528 & 1) == 1;
  DAT_ffffb4f8 = (DAT_ffffb528 & 2) != 0;
  DAT_ffffb4f9 = (DAT_ffffb528 & 4) != 0;
  DAT_ffffb4fa = (DAT_ffffb528 & 8) != 0;
  DAT_ffffb4fb = (DAT_ffffb528 & 0x10) != 0;
  DAT_ffffb4fc = (DAT_ffffb528 & 0x20) != 0;
  DAT_ffffb4fd = (DAT_ffffb528 & 0x40) != 0;
  DAT_ffffb4fe = ((int)(char)DAT_ffffb528 & 0x80U) != 0;
  FUN_00024b00((int)DAT_ffffb48d,&DAT_ffffb530,&DAT_ffffb529);
  DAT_ffffb4ff = (DAT_ffffb529 & 1) == 1;
  DAT_ffffb500 = (DAT_ffffb529 & 2) != 0;
  DAT_ffffb501 = (DAT_ffffb529 & 4) != 0;
  DAT_ffffb502 = (DAT_ffffb529 & 8) != 0;
  DAT_ffffb503 = (DAT_ffffb529 & 0x10) != 0;
  DAT_ffffb504 = (DAT_ffffb529 & 0x20) != 0;
  DAT_ffffb505 = (DAT_ffffb529 & 0x40) != 0;
  DAT_ffffb506 = ((int)(char)DAT_ffffb529 & 0x80U) != 0;
  FUN_00024b00((int)DAT_ffffb48e,&DAT_ffffb531,&DAT_ffffb52a);
  DAT_ffffb507 = (DAT_ffffb52a & 1) == 1;
  DAT_ffffb508 = (DAT_ffffb52a & 2) != 0;
  DAT_ffffb509 = (DAT_ffffb52a & 4) != 0;
  DAT_ffffb50a = (DAT_ffffb52a & 8) != 0;
  DAT_ffffb50b = (DAT_ffffb52a & 0x10) != 0;
  FUN_00024b00((int)DAT_ffffb48f,&DAT_ffffb532,&DAT_ffffb52b);
  DAT_ffffb50c = (DAT_ffffb52b & 1) == 1;
  DAT_ffffb50d = (DAT_ffffb52b & 2) != 0;
  DAT_ffffb50e = (DAT_ffffb52b & 4) != 0;
  DAT_ffffb50f = (DAT_ffffb52b & 8) != 0;
  DAT_ffffb510 = (DAT_ffffb52b & 0x10) != 0;
  DAT_ffffb511 = (DAT_ffffb52b & 0x20) != 0;
  DAT_ffffb512 = (DAT_ffffb52b & 0x40) != 0;
  DAT_ffffb513 = ((int)(char)DAT_ffffb52b & 0x80U) != 0;
  FUN_00024b00((int)DAT_ffffb490,&DAT_ffffb533,&DAT_ffffb52c);
  DAT_ffffb514 = (DAT_ffffb52c & 1) == 1;
  DAT_ffffb515 = (DAT_ffffb52c & 2) != 0;
  DAT_ffffb516 = (DAT_ffffb52c & 4) != 0;
  DAT_ffffb517 = (DAT_ffffb52c & 8) != 0;
  DAT_ffffb518 = (DAT_ffffb52c & 0x10) != 0;
  DAT_ffffb519 = (DAT_ffffb52c & 0x20) != 0;
  DAT_ffffb51a = (DAT_ffffb52c & 0x40) != 0;
  DAT_ffffb51b = ((int)(char)DAT_ffffb52c & 0x80U) != 0;
  DAT_ffffb4d6 = DAT_ffffb492;
  DAT_ffffb4d7 = DAT_ffffb493;
  DAT_ffffb4d8 = DAT_ffffb494;
  DAT_ffffb4d9 = DAT_ffffb495;
  DAT_ffffb4da = DAT_ffffb496;
  DAT_ffffb4db = DAT_ffffb497;
  uVar2 = 0x38a00000;
  DAT_ffffb4c0 = rx8_decode_u16_affine(0x38a00000,uVar3,(int)DAT_ffffb498);
  DAT_ffffb4c4 = rx8_decode_u16_affine(uVar2,uVar3,(int)DAT_ffffb49a);
  DAT_ffffb4c8 = rx8_decode_u16_affine(uVar2,uVar3,(int)DAT_ffffb49c);
  return;
}


