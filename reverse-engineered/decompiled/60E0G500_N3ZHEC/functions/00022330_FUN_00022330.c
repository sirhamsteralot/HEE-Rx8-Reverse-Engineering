/* ROM address: 0x00022330; body bytes: 250; decompiled */

void FUN_00022330(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_1c;
  undefined4 auStack_18 [2];
  
  cVar1 = DAT_ffffaae0;
  if (DAT_ffffaa10 < 200.0) {
    if (DAT_ffffaa10 < 197.0) {
      DAT_ffffb324 = '\0';
    }
  }
  else {
    DAT_ffffb324 = '\x01';
  }
  if ((DAT_ffffaae0 == '\0') && (DAT_ffffb325 == '\x01')) {
    DAT_ffffb322 = 0xbc;
  }
  else if (DAT_ffffb322 != 0) {
    DAT_ffffb322 = DAT_ffffb322 + -1;
  }
  if ((DAT_ffffbf39 == '\x01') ||
     (((DAT_ffffaae0 == '\0' && (DAT_ffffb322 != 0)) && (DAT_ffffb324 == '\0')))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  DAT_ffffb320 = FUN_0005d150(uVar2);
  if (DAT_ffffb320 == '\x01') {
    FUN_00002054(auStack_18,0xe0);
    FUN_00004bbc(0xfffff754,0x80,1);
  }
  else {
    FUN_00002054(&local_1c,0xe0);
    FUN_00004bbc(0xfffff754,0x80,0);
    auStack_18[0] = local_1c;
  }
  FUN_00002064(auStack_18[0]);
  DAT_ffffb325 = cVar1;
  return;
}


