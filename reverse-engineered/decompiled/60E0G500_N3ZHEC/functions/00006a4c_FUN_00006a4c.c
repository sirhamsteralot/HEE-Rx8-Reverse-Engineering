/* ROM address: 0x00006a4c; body bytes: 248; decompiled */

undefined4 FUN_00006a4c(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  FUN_00006b94();
  FUN_00006c4c();
  adc_read_ect_iat_group();
  if (DAT_ffff9f28 == '\x02') {
    DAT_ffff9ee2 = DAT_ffff9ee2 + '\x01';
LAB_00006a84:
    DAT_ffff9ee1 = DAT_ffff9ee1 + '\x01';
  }
  else {
    if (DAT_ffff9f28 == '\x01') goto LAB_00006a84;
    if (DAT_ffff9f28 != '\0') goto LAB_00006a90;
  }
  DAT_ffff9ee0 = DAT_ffff9ee0 + '\x01';
LAB_00006a90:
  DAT_ffff9f24 = DAT_ffff9f24 + 1;
  DAT_ffff9f25 = 0;
  if ((DAT_ffff9f24 & 0xf) == 0) {
    DAT_ffff9f28 = 2;
    DAT_ffff9f2b = '\f';
    DAT_ffff9f2e = '\f';
    DAT_ffff9f31 = '\b';
    DAT_ffff9f26 = DAT_ffff9f26 + 1;
    if (3 < DAT_ffff9f26) {
      DAT_ffff9f25 = 1;
      DAT_ffff9f26 = 0;
    }
  }
  else {
    bVar1 = (DAT_ffff9f24 & 3) != 0;
    if (bVar1) {
      DAT_ffff9f2e = '\x04';
      DAT_ffff9f2b = '\x04';
    }
    else {
      DAT_ffff9f2b = '\f';
      DAT_ffff9f2e = '\b';
    }
    DAT_ffff9f28 = !bVar1;
    DAT_ffff9f31 = '\0';
  }
  if (DAT_ffff9f2b != '\0') {
    FUN_00006d7c();
  }
  if (DAT_ffff9f2e != '\0') {
    uVar2 = FUN_00003920(0x90);
    DAT_ffff9f27 = 0;
    FUN_00006de2();
    FUN_00003934(uVar2);
  }
  if (DAT_ffff9f31 == '\0') {
    return 0;
  }
  uVar2 = FUN_00006ec4();
  return uVar2;
}


