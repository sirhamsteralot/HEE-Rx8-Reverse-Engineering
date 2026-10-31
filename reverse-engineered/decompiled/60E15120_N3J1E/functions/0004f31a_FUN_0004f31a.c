/* ROM address: 0x0004f31a; body bytes: 168; decompiled */

void FUN_0004f31a(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  
  cVar4 = DAT_ffffd0f2;
  cVar3 = DAT_ffffd0a8;
  cVar2 = DAT_ffffd040;
  cVar1 = DAT_ffffcf85;
  uVar5 = sh_raise_interrupt_mask_return_previous(0x10);
  if (DAT_ffffcfbe == '\0') {
    DAT_ffffcfe0 = 0;
  }
  if (((((DAT_ffffd003 == '\0') && (cVar2 == '\x01')) ||
       ((DAT_ffffd004 == '\0' && (cVar3 == '\x01')))) ||
      ((DAT_ffffd002 == '\0' && (cVar4 == '\x01')))) || ((DAT_ffffd000 == '\0' && (cVar1 != '\0'))))
  {
    DAT_ffffcfe8 = 0x3d1ba5e3;
  }
  ref_setSR(uVar5);
  DAT_ffffd000 = cVar1;
  DAT_ffffd003 = cVar2;
  DAT_ffffd004 = cVar3;
  DAT_ffffd002 = cVar4;
  return;
}


