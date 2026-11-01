/* ROM address: 0x0002d368; body bytes: 328; decompiled */

char FUN_0002d368(void)

{
  if (DAT_ffffc12c < 0.25) {
    if (DAT_ffffc12c < 0.21000001) {
      DAT_ffffbcf4 = '\0';
    }
  }
  else {
    DAT_ffffbcf4 = '\x01';
  }
  if (DAT_ffffaa10 < 0.0) {
    if (DAT_ffffaa10 < -5.0) {
      DAT_ffffbcf5 = '\0';
    }
  }
  else {
    DAT_ffffbcf5 = '\x01';
  }
  if (DAT_ffffb5b8 < 4800.0) {
    if (DAT_ffffb5b8 < 4700.0) {
      DAT_ffffbcf7 = '\0';
    }
  }
  else {
    DAT_ffffbcf7 = '\x01';
  }
  if (DAT_ffffb5b8 < 9500.0) {
    if (DAT_ffffb5b8 < 9400.0) {
      DAT_ffffbcf8 = '\0';
    }
  }
  else {
    DAT_ffffbcf8 = '\x01';
  }
  if (DAT_ffffb5b8 < 10000.0) {
    if (DAT_ffffb5b8 < 9900.0) {
      DAT_ffffbcf9 = '\0';
    }
  }
  else {
    DAT_ffffbcf9 = '\x01';
  }
  if (DAT_ffffb5b8 < 11000.0) {
    if (DAT_ffffb5b8 < 10900.0) {
      DAT_ffffbcfa = '\0';
    }
  }
  else {
    DAT_ffffbcfa = '\x01';
  }
  if (DAT_ffffbcf4 == '\x01') {
    if (DAT_ffffbcf5 == '\x01') {
      DAT_ffffbcee = '\x0f';
    }
    else {
      DAT_ffffbcee = '\n';
    }
  }
  else if (DAT_ffffbcf5 == '\x01') {
    DAT_ffffbcee = '\x05';
  }
  else {
    DAT_ffffbcee = '\0';
  }
  if (DAT_ffffbcf7 != '\0') {
    if (DAT_ffffbcf8 == '\0') {
      DAT_ffffbcee = DAT_ffffbcee + '\x01';
    }
    else if (DAT_ffffbcf9 == '\0') {
      DAT_ffffbcee = DAT_ffffbcee + '\x02';
    }
    else if (DAT_ffffbcfa == '\0') {
      DAT_ffffbcee = DAT_ffffbcee + '\x03';
    }
    else {
      DAT_ffffbcee = DAT_ffffbcee + '\x04';
    }
  }
  return DAT_ffffbcf5;
}


