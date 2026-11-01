/* ROM address: 0x00030df0; body bytes: 76; decompiled */

void FUN_00030df0(void)

{
  float fVar1;
  
  if ((DAT_ffffa428 == '\0') || (DAT_ffffbea8 != '\0')) {
    fVar1 = DAT_ffffbed4 * 1.0 * DAT_ffffbee8 * DAT_ffffbeec * DAT_ffffbef0;
    DAT_ffffbec4 = DAT_ffffbef4 * fVar1;
    DAT_ffffbec8 = DAT_ffffbef8 * fVar1;
  }
  return;
}


