/* ROM address: 0x00024b8c; body bytes: 630; decompiled */

char FUN_00024b8c(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  
  cVar3 = DAT_ffffbaec;
  cVar2 = DAT_ffffb53f;
  cVar4 = DAT_ffffb53d;
  if (DAT_ffffb534 == '\x01') {
    cVar4 = '\x01';
    if ((DAT_ffffb53b == '\x01') || (cVar4 = DAT_ffffbf9c, DAT_ffffbf9c == '\x01')) {
      DAT_ffffb53a = 1;
    }
    else {
      DAT_ffffb53a = 0;
    }
    DAT_ffffb53c = 0;
    DAT_ffffb53e = 0;
    DAT_ffffb540 = 0;
    return cVar4;
  }
  bVar1 = DAT_ffffbaec == '\a';
  if (bVar1 == (bool)DAT_ffffb53f) {
    DAT_ffffb53f = bVar1;
    if (DAT_ffffb544 == '\x01') {
      DAT_ffffb542 = rx8_add_u8_saturate((int)(char)DAT_ffffb542,1);
    }
  }
  else {
    DAT_ffffb542 = 0;
    DAT_ffffb544 = '\x01';
    DAT_ffffb53f = bVar1;
  }
  if (cVar3 == '\0') {
    DAT_ffffb53a = 1;
  }
  else {
    DAT_ffffb53a = 0;
    if (cVar3 != '\a') {
      DAT_ffffb53d = '\x01';
      goto LAB_00024c72;
    }
  }
  DAT_ffffb53d = '\0';
LAB_00024c72:
  if (DAT_ffffb53d == cVar4) {
    if (DAT_ffffb543 == '\x01') {
      DAT_ffffb541 = rx8_add_u8_saturate((int)(char)DAT_ffffb541,1);
    }
  }
  else {
    DAT_ffffb541 = 0;
    DAT_ffffb543 = '\x01';
  }
  if ((cVar4 == '\x01') && (DAT_ffffb53d == '\0')) {
    DAT_ffffb538 = '\x03';
  }
  else if (DAT_ffffb53f == '\x01') {
    DAT_ffffb538 = '\0';
  }
  else if (DAT_ffffb538 != '\0') {
    DAT_ffffb538 = DAT_ffffb538 + -1;
  }
  if (DAT_ffffb53f == '\0') {
    if (cVar2 == '\x01') {
      DAT_ffffb539 = '\x16';
    }
    else if (DAT_ffffb539 != '\0') {
      DAT_ffffb539 = DAT_ffffb539 + -1;
    }
  }
  else {
    DAT_ffffb539 = '\0';
  }
  if (DAT_ffffb53d == '\x01') {
    if ((DAT_ffffb538 == '\0') && (DAT_ffffb539 == '\0')) {
      if (20.0 < vehicle_speed_ffffbbb4) {
        if (0x5d < DAT_ffffb541) {
          DAT_ffffb540 = '\x01';
        }
      }
      else if (9 < DAT_ffffb541) {
        DAT_ffffb540 = '\x01';
      }
    }
    if ((DAT_ffffa7b8 == '\x01') && (2000.0 < engine_speed_rpm_ffffb548)) {
      DAT_ffffb540 = '\x01';
    }
  }
  else if (0xb < DAT_ffffb541) {
    DAT_ffffb540 = '\0';
  }
  if ((DAT_ffffb540 == '\x01') || ((DAT_ffffb53f == '\0' && (2 < DAT_ffffb542)))) {
    DAT_ffffb53e = '\0';
  }
  else if ((DAT_ffffb53f == '\x01') &&
          ((5 < DAT_ffffb542 || ((DAT_ffffa7b8 == '\x01' && (2000.0 < engine_speed_rpm_ffffb548)))))) {
    DAT_ffffb53e = '\x01';
  }
  cVar4 = '\x01';
  if ((DAT_ffffb540 == '\x01') || (cVar4 = DAT_ffffb53e, DAT_ffffb53e == '\x01')) {
    DAT_ffffb53c = 1;
  }
  else {
    DAT_ffffb53c = 0;
  }
  return cVar4;
}


