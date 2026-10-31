/* ROM address: 0x00029074; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00029a1c (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_CAN231TX_Main(void)

{
  uint uVar1;
  
  uVar1 = ref_placeCANRX(&DAT_0004df5c);
  if ((uVar1 & 0xff) == 0) {
    FUN_0000e040();
    ref_can231SetupTx();
    ref_can231TxPack();
    uVar1 = FUN_00029134();
    return uVar1;
  }
  return uVar1 & 0xff;
}


