/* ROM address: 0x000215d6; body bytes: 316; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0002164e) */
/* WARNING: Removing unreachable block (ram,0x0002165a) */
/* WARNING: Removing unreachable block (ram,0x00021662) */
/* WARNING: Removing unreachable block (ram,0x00021680) */
/* WARNING: Removing unreachable block (ram,0x00021676) */
/* WARNING: Removing unreachable block (ram,0x00021688) */

uint FUN_000215d6(void)

{
  undefined1 uVar1;
  char cVar2;
  byte *pbVar3;
  uint uVar4;
  
  cVar2 = DAT_ffffaadb;
  uVar1 = DAT_ffffaada;
  if (((((DAT_ffffb13c == '\0') && (DAT_ffffb2d8 == '\0')) && (DAT_ffffb2d9 == '\0')) &&
      ((0x270 < DAT_ffffa424 && ((0x2c < DAT_ffffb2ca || (DAT_ffffb2d7 == 0)))))) &&
     ((DAT_ffffb2d6 == '\x01' && (DAT_ffffaadb == '\0')))) {
    DAT_ffffb2d7 = 1;
    DAT_ffffb2ce = 0;
    DAT_ffffb2ca = 0;
    if (DAT_ffffb5aa == '\x01') {
      pbVar3 = &DAT_00072b7f;
    }
    else {
      pbVar3 = &DAT_00072b80;
    }
    DAT_ffffb2bc = 0x43fa0000;
    DAT_ffffb2c0 = *pbVar3;
  }
  uVar4 = (uint)DAT_ffffb2d7;
  if (uVar4 == 1) {
    if (DAT_ffffb2ce < DAT_ffffb2c0) {
      FUN_00009630(0,1,&DAT_ffffb2bc);
      DAT_ffffb2ce = FUN_00002478((int)(char)DAT_ffffb2ce,1);
    }
    uVar4 = FUN_00002460((int)(short)DAT_ffffb2ca,1);
    DAT_ffffb2ca = (ushort)uVar4;
  }
  DAT_ffffb2d5 = uVar1;
  DAT_ffffb2d6 = cVar2;
  return uVar4;
}


