/* ROM address: 0x0002507a; body bytes: 1408; decompiled */

void FUN_0002507a(void)

{
  ushort uVar1;
  char cVar2;
  undefined4 uVar3;
  
  DAT_ffffb4b2 = FUN_00002490(DAT_ffffb47c,0x3cfa0000,0);
  DAT_ffffb4b4 = DAT_ffffb4b2;
  if (DAT_ffffb484 < 0.0) {
    uVar1 = FUN_00002490(-DAT_ffffb484,0x3cfa0000,0);
    DAT_ffffb4b6 = ~uVar1 + 1;
  }
  else {
    DAT_ffffb4b6 = FUN_00002490(DAT_ffffb484,0x3cfa0000,0);
  }
  DAT_ffffb4b8 = FUN_00002490(DAT_ffffb604,0x39a00000,0);
  uVar3 = FUN_0003eb72(0x41700000,&DAT_ffff80a4);
  DAT_ffffb4ba = FUN_00002490(uVar3,0x3cfa0000,0);
  uVar3 = FUN_0003eb72(0x41700000,&DAT_ffff80ac);
  DAT_ffffb4bc = FUN_00002490(uVar3,0x3cfa0000,0);
  DAT_ffffb4be = DAT_ffffaa4c;
  DAT_ffffb4c0 = DAT_ffffb58e;
  DAT_ffffb4c2 = DAT_ffffb590;
  DAT_ffffb4c4 = DAT_ffffb592;
  DAT_ffffb4c6 = DAT_ffffb594;
  DAT_ffffb4c8 = DAT_ffffccd1;
  if (DAT_ffffaae0 == '\x01') {
    DAT_ffffb4c9 = DAT_ffffb4c9 | 1;
  }
  else {
    DAT_ffffb4c9 = DAT_ffffb4c9 & 0xfe;
  }
  if (DAT_ffffcd01 == '\x01') {
    DAT_ffffb4c9 = DAT_ffffb4c9 | 2;
  }
  else {
    DAT_ffffb4c9 = DAT_ffffb4c9 & 0xfd;
  }
  if (DAT_ffffbd59 == '\x01') {
    DAT_ffffb4c9 = DAT_ffffb4c9 | 4;
  }
  else {
    DAT_ffffb4c9 = DAT_ffffb4c9 & 0xfb;
  }
  if (DAT_ffffcd09 == '\x01') {
    DAT_ffffb4c9 = DAT_ffffb4c9 | 8;
  }
  else {
    DAT_ffffb4c9 = DAT_ffffb4c9 & 0xf7;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff80c8,0);
  if (cVar2 == '\x01') {
    DAT_ffffb4c9 = DAT_ffffb4c9 | 0x10;
  }
  else {
    DAT_ffffb4c9 = DAT_ffffb4c9 & 0xef;
  }
  if (DAT_ffffadd8 == '\x01') {
    DAT_ffffb4c9 = DAT_ffffb4c9 | 0x20;
  }
  else {
    DAT_ffffb4c9 = DAT_ffffb4c9 & 0xdf;
  }
  if (DAT_ffffadda == '\x01') {
    DAT_ffffb4c9 = DAT_ffffb4c9 | 0x40;
  }
  else {
    DAT_ffffb4c9 = DAT_ffffb4c9 & 0xbf;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff878a,0);
  if (cVar2 == '\x01') {
    DAT_ffffb4c9 = DAT_ffffb4c9 | 0x80;
  }
  else {
    DAT_ffffb4c9 = DAT_ffffb4c9 & 0x7f;
  }
  if (DAT_ffffb54f == '\x01') {
    DAT_ffffb4ca = DAT_ffffb4ca | 1;
  }
  else {
    DAT_ffffb4ca = DAT_ffffb4ca & 0xfe;
  }
  if (DAT_ffffb550 == '\x01') {
    DAT_ffffb4ca = DAT_ffffb4ca | 2;
  }
  else {
    DAT_ffffb4ca = DAT_ffffb4ca & 0xfd;
  }
  if (DAT_ffffb551 == '\x01') {
    DAT_ffffb4ca = DAT_ffffb4ca | 0x10;
  }
  else {
    DAT_ffffb4ca = DAT_ffffb4ca & 0xef;
  }
  if (DAT_ffffb552 == '\x01') {
    DAT_ffffb4ca = DAT_ffffb4ca | 0x20;
  }
  else {
    DAT_ffffb4ca = DAT_ffffb4ca & 0xdf;
  }
  if (DAT_ffffb553 == '\x01') {
    DAT_ffffb4ca = DAT_ffffb4ca | 0x40;
  }
  else {
    DAT_ffffb4ca = DAT_ffffb4ca & 0xbf;
  }
  if (DAT_ffffb554 == '\x01') {
    DAT_ffffb4ca = DAT_ffffb4ca | 0x80;
  }
  else {
    DAT_ffffb4ca = DAT_ffffb4ca & 0x7f;
  }
  if (DAT_ffffb54c == '\x01') {
    DAT_ffffb4cb = DAT_ffffb4cb | 1;
  }
  else {
    DAT_ffffb4cb = DAT_ffffb4cb & 0xfe;
  }
  if (DAT_ffffb54e == '\x01') {
    DAT_ffffb4cb = DAT_ffffb4cb | 2;
  }
  else {
    DAT_ffffb4cb = DAT_ffffb4cb & 0xfd;
  }
  if (DAT_ffffb54d == '\x01') {
    DAT_ffffb4cb = DAT_ffffb4cb | 4;
  }
  else {
    DAT_ffffb4cb = DAT_ffffb4cb & 0xfb;
  }
  if (DAT_ffffb555 == '\x01') {
    DAT_ffffb4cb = DAT_ffffb4cb | 0x10;
  }
  else {
    DAT_ffffb4cb = DAT_ffffb4cb & 0xef;
  }
  if (DAT_ffffb556 == '\x01') {
    DAT_ffffb4cb = DAT_ffffb4cb | 0x20;
  }
  else {
    DAT_ffffb4cb = DAT_ffffb4cb & 0xdf;
  }
  if (DAT_ffffb557 == '\x01') {
    DAT_ffffb4cb = DAT_ffffb4cb | 0x40;
  }
  else {
    DAT_ffffb4cb = DAT_ffffb4cb & 0xbf;
  }
  if (DAT_ffffb558 == '\x01') {
    DAT_ffffb4cb = DAT_ffffb4cb | 0x80;
  }
  else {
    DAT_ffffb4cb = DAT_ffffb4cb & 0x7f;
  }
  if (DAT_ffffb559 == '\x01') {
    DAT_ffffb4cc = DAT_ffffb4cc | 1;
  }
  else {
    DAT_ffffb4cc = DAT_ffffb4cc & 0xfe;
  }
  if (DAT_ffffb58c == '\x01') {
    DAT_ffffb4cc = DAT_ffffb4cc | 2;
  }
  else {
    DAT_ffffb4cc = DAT_ffffb4cc & 0xfd;
  }
  if (DAT_ffffb55a == '\x01') {
    DAT_ffffb4cc = DAT_ffffb4cc | 4;
  }
  else {
    DAT_ffffb4cc = DAT_ffffb4cc & 0xfb;
  }
  if (DAT_ffffb33f == '\x01') {
    DAT_ffffb4cc = DAT_ffffb4cc | 8;
  }
  else {
    DAT_ffffb4cc = DAT_ffffb4cc & 0xf7;
  }
  if (DAT_ffffb340 == '\x01') {
    DAT_ffffb4cc = DAT_ffffb4cc | 0x10;
  }
  else {
    DAT_ffffb4cc = DAT_ffffb4cc & 0xef;
  }
  if (DAT_ffffb492 == '\x01') {
    DAT_ffffb4cc = DAT_ffffb4cc | 0x20;
  }
  else {
    DAT_ffffb4cc = DAT_ffffb4cc & 0xdf;
  }
  if (DAT_ffffc098 == '\x01') {
    DAT_ffffb4cc = DAT_ffffb4cc | 0x40;
  }
  else {
    DAT_ffffb4cc = DAT_ffffb4cc & 0xbf;
  }
  if (DAT_ffffadd9 == '\x01') {
    DAT_ffffb4cd = DAT_ffffb4cd | 1;
  }
  else {
    DAT_ffffb4cd = DAT_ffffb4cd & 0xfe;
  }
  if (DAT_ffffaddb == '\x01') {
    DAT_ffffb4cd = DAT_ffffb4cd | 2;
  }
  else {
    DAT_ffffb4cd = DAT_ffffb4cd & 0xfd;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff80ca,1);
  if (cVar2 == '\x01') {
    DAT_ffffb4cd = DAT_ffffb4cd | 4;
  }
  else {
    DAT_ffffb4cd = DAT_ffffb4cd & 0xfb;
  }
  if (DAT_ffffcd07 == '\x01') {
    DAT_ffffb4cd = DAT_ffffb4cd | 8;
  }
  else {
    DAT_ffffb4cd = DAT_ffffb4cd & 0xf7;
  }
  if (DAT_ffffccfd == '\x01') {
    DAT_ffffb4cd = DAT_ffffb4cd | 0x10;
  }
  else {
    DAT_ffffb4cd = DAT_ffffb4cd & 0xef;
  }
  if (DAT_ffffccfc == '\x01') {
    DAT_ffffb4cd = DAT_ffffb4cd | 0x20;
  }
  else {
    DAT_ffffb4cd = DAT_ffffb4cd & 0xdf;
  }
  if (DAT_ffffb55b == '\x01') {
    DAT_ffffb4cd = DAT_ffffb4cd | 0x40;
  }
  else {
    DAT_ffffb4cd = DAT_ffffb4cd & 0xbf;
  }
  if (DAT_ffffcd08 == '\x01') {
    DAT_ffffb4cd = DAT_ffffb4cd | 0x80;
  }
  else {
    DAT_ffffb4cd = DAT_ffffb4cd & 0x7f;
  }
  uVar3 = FUN_0003eb72(0x41a00000,&DAT_ffff80bc);
  DAT_ffffb4ce = FUN_00002490(uVar3,0x3cfa0000,0);
  DAT_ffffb4d0 = FUN_00002490(DAT_ffffb3fc,0x3cfa0000,0);
  uVar3 = FUN_0003eb72(0x412db22d,&DAT_ffff8090);
  DAT_ffffb4d2 = FUN_00002490(uVar3,0x3b800000,0);
  DAT_ffffb4d4 = FUN_00002490(DAT_ffffb5b8,0x3e480000,0);
  return;
}


