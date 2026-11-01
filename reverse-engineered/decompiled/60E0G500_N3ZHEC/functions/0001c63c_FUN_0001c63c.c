/* ROM address: 0x0001c63c; body bytes: 224; decompiled */

void FUN_0001c63c(void)

{
  float fVar1;
  float fVar2;
  float arg0;
  
  fVar1 = (float)FUN_0003eb72(0x41700000,&DAT_ffff80a4);
  fVar1 = DAT_ffffada8 - fVar1;
  fVar2 = (float)FUN_0003eb72(0x41700000,&DAT_ffff80ac);
  arg0 = 0.0;
  fVar2 = DAT_ffffadac - fVar2;
  DAT_ffffadb0 = rx8_max_float(0.0,fVar1);
  DAT_ffffadb4 = rx8_max_float(arg0,fVar2);
  if (DAT_ffffccd8 == '\x01') {
    DAT_ffffadbc = DAT_ffffadb4;
    if (DAT_ffffccd9 == '\x01') {
      DAT_ffffadbc = 20.0;
    }
  }
  else {
    DAT_ffffadbc = DAT_ffffadb0;
  }
  DAT_ffffadb8 = rx8_max_float(arg0,DAT_ffffadbc - DAT_ffffb314);
  fVar1 = (float)FUN_0003ea74(DAT_ffffadbc,0x42a80000);
  DAT_ffffadc0 = fVar1 * 100.0;
  DAT_ffffadc4 = DAT_ffffadb8 - DAT_ffffae24;
  DAT_ffffae24 = DAT_ffffae20;
  DAT_ffffae20 = DAT_ffffadb8;
  DAT_ffffadc8 = DAT_ffffadbc - DAT_ffffae0c;
  DAT_ffffae0c = DAT_ffffae08;
  DAT_ffffae08 = DAT_ffffadbc;
  return;
}


