/* [ADDITIONAL SOURCE REVIEW]
 * uds_rx_channel_alloc [high]: finds free/busy channel slot in DAT_ffffddf4, binds service via 0x68b10 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x00068a86; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067376 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

int uds_rx_channel_alloc(char param_1)

{
  bool bVar1;
  int iVar2;
  int unaff_r14;
  
  bVar1 = true;
  iVar2 = 0;
  do {
    if ((&DAT_ffffddf4)[iVar2 * 2] == '\x04') {
      bVar1 = false;
      unaff_r14 = iVar2;
      break;
    }
    if (((&DAT_ffffddf4)[iVar2 * 2] == '\0') && (bVar1)) {
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


