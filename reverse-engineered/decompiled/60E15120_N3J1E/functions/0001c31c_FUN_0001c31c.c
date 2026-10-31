/* ROM address: 0x0001c31c; body bytes: 104; decompiled */

void FUN_0001c31c(void)

{
  char cVar1;
  char cVar2;
  
  cVar2 = secondary_air_pump_request_ffffbf6c;
  cVar1 = DAT_ffffb53a;
  if ((secondary_air_pump_request_ffffbf6c == '\0') && (DAT_ffffb06e == '\x01')) {
    DAT_ffffb064 = 0;
  }
  else {
    DAT_ffffb064 = rx8_add_u8_saturate((int)DAT_ffffb064,1);
  }
  if ((cVar1 == '\x01') && (DAT_ffffb06f == '\0')) {
    DAT_ffffb065 = 0;
  }
  else {
    DAT_ffffb065 = rx8_add_u8_saturate((int)DAT_ffffb065,1);
  }
  DAT_ffffb06e = cVar2;
  DAT_ffffb06f = cVar1;
  return;
}


