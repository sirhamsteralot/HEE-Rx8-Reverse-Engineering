/* ROM address: 0x00001858; body bytes: 266; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000018aa) */

void FUN_00001858(int param_1)

{
  byte bVar1;
  short sVar2;
  
  sVar2 = *(short *)(param_1 + 2);
  bVar1 = *(byte *)(param_1 + 4);
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x27;
  DAT_ffffdfc8 = 2;
  if (DAT_ffffdfb0 == '\0') {
    DAT_ffffdfcb = 0x22;
    goto LAB_0000196a;
  }
  if ((sVar2 != 0) && (bVar1 != 0)) {
    if ((bVar1 & 1) == 1) {
      if (sVar2 == 1) {
        DAT_ffffdfb2 = '\0';
        if (bVar1 == 1) {
          DAT_ffffdfc6 = 0x67;
          DAT_ffffdfca = 1;
          DAT_ffffdfc8 = 4;
          if (DAT_ffffdfb1 == '\x01') {
            DAT_ffffdfcb = 0;
            DAT_ffffdfcc = 0;
            DAT_ffffdfcd = 0;
          }
          else {
            DAT_ffffdfcb = 0x55;
            DAT_ffffdfcc = 0xaa;
            DAT_ffffdfcd = 0x55;
            DAT_ffffdfb2 = '\x01';
          }
        }
        else {
          DAT_ffffdfcb = 0x31;
        }
        goto LAB_0000196a;
      }
    }
    else if (sVar2 == 4) {
      if ((DAT_ffffdfb2 == '\0') || (bVar1 != 2)) {
        DAT_ffffdfcb = 0x22;
      }
      else if (((*(char *)(param_1 + 5) == 'M') && (*(char *)(param_1 + 6) == -0x54)) &&
              (*(char *)(param_1 + 7) == -0x33)) {
        DAT_ffffdfb1 = '\x01';
        DAT_ffffdfc6 = 0x67;
        DAT_ffffdfca = 2;
        DAT_ffffdfc8 = 1;
      }
      else {
        DAT_ffffdfcb = 0x35;
      }
      DAT_ffffdfb2 = '\0';
      goto LAB_0000196a;
    }
  }
  DAT_ffffdfcb = 0x12;
LAB_0000196a:
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}


