/* ROM address: 0x00028b08; body bytes: 112; decompiled */

char FUN_00028b08(void)

{
  ushort uVar1;
  char cVar2;
  float fVar3;
  
  uVar1 = DAT_ffffb6d0 & 1;
  fVar3 = (float)FUN_00002500(0x3c000000,0,0);
  if ((((DAT_ffffb5aa != '\x01') && (cVar2 = DAT_ffffb5aa, DAT_ffffc12c < fVar3)) ||
      (cVar2 = DAT_ffffb70c, DAT_ffffb70c != '\x01')) ||
     ((cVar2 = DAT_ffffb736, DAT_ffffb736 != '\x01' || (DAT_ffffbaa8 <= DAT_ffffbae0)))) {
    (&DAT_ffffba90)[uVar1] = 0;
  }
  else {
    cVar2 = '\x01';
    (&DAT_ffffba90)[uVar1] = 1;
  }
  return cVar2;
}


