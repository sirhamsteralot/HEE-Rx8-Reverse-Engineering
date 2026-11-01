/* ROM address: 0x00030714; body bytes: 164; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00030774) */

char FUN_00030714(void)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = DAT_ffffa42c;
  if (DAT_ffffbe2c < DAT_ffffbe30) {
    if (DAT_ffffbe2c < DAT_ffffbe30 - 3.5) {
      DAT_ffffbe41 = '\0';
    }
  }
  else {
    DAT_ffffbe41 = '\x01';
  }
  if (((DAT_ffffbe41 == '\x01') && (DAT_ffffa41c == '\0')) ||
     ((DAT_ffffa42c == '\x01' && (DAT_ffffaae0 == '\x01')))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  DAT_ffffbe28 = FUN_0005ca88(uVar2);
  if (cVar1 == '\x01') {
    DAT_ffffbe40 = '\x01';
  }
  else if (DAT_ffffbe40 != '\0') {
    DAT_ffffbe40 = DAT_ffffbe40 + -1;
  }
  return cVar1;
}


