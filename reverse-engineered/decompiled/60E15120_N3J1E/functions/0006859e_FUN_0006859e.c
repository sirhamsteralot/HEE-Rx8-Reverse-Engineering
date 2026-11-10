/* [ADDITIONAL SOURCE REVIEW]
 * isotp_first_frame_accept [high]: FF: total len=(pci&0xf)*256+buf[2], service=buf[3], starts reassembly
 */
/* ROM address: 0x0006859e; body bytes: 130; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066e8e (130 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint isotp_first_frame_accept(void)

{
  uint uVar1;
  
  uVar1 = (uds_rx_buffer_ffffddc8 & 0xf) * 0x100 + (uint)DAT_ffffddc9;
  if ((uVar1 < 0x1000) && (7 < uVar1)) {
    DAT_ffffddf5 = DAT_ffffddf5 | 4;
    FUN_000683b4();
    DAT_ffffddec = uds_rx_channel_alloc((int)DAT_ffffddca);
    DAT_ffffddeb = 2;
    DAT_ffffdde6 = (undefined2)uVar1;
    DAT_ffffddea = DAT_ffffddca;
    DAT_ffffdde8 = 6;
    DAT_ffffdded = 1;
    ref_pack_for_OBD_response_((int)DAT_ffffddec,&DAT_ffffddca,6);
    FUN_00068bc6(6,5);
    uVar1 = thunk_FUN_00054b62((int)DAT_ffffddea);
    return uVar1;
  }
  return (uint)DAT_ffffddc9;
}


