/* ROM address: 0x00027fb4; body bytes: 110; decompiled */

char FUN_00027fb4(void)

{
  ushort uVar1;
  char cVar2;
  
  uVar1 = sector_parity_bank_ffffb660 & 1;
  DAT_ffffba28 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&DAT_0006a6b8);
  if ((((DAT_ffffb53a != '\x01') && (cVar2 = DAT_ffffb53a, engine_load_ffffc0b4 < DAT_ffffba28)) ||
      (cVar2 = DAT_ffffb69c, DAT_ffffb69c != '\x01')) ||
     ((cVar2 = DAT_ffffb6c6, DAT_ffffb6c6 != '\x01' || (DAT_ffffba40 <= DAT_ffffba78)))) {
    (&DAT_ffffba24)[uVar1] = 0;
  }
  else {
    cVar2 = '\x01';
    (&DAT_ffffba24)[uVar1] = 1;
  }
  return cVar2;
}


