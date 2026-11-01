/* ROM address: 0x0006922a; body bytes: 98; decompiled */

int uds_rx_channel_alloc(char param_1)

{
  bool bVar1;
  int iVar2;
  int unaff_r14;
  
  bVar1 = true;
  iVar2 = 0;
  do {
    if ((&DAT_ffffde30)[iVar2 * 2] == '\x04') {
      bVar1 = false;
      unaff_r14 = iVar2;
      break;
    }
    if (((&DAT_ffffde30)[iVar2 * 2] == '\0') && (bVar1)) {
      bVar1 = false;
      unaff_r14 = iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  if (!bVar1) {
    uds_rx_channel_set_service(unaff_r14,(int)param_1);
  }
  return unaff_r14;
}


