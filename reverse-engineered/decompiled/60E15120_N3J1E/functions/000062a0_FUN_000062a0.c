/* ROM address: 0x000062a0; body bytes: 192; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000062a0 (192 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000062a0(void)

{
  byte bVar1;
  undefined4 local_4;
  
  do {
    FUN_0000a50e();
    FUN_00004cb6();
    FUN_00007088();
    FUN_000069e2();
    FUN_000074b0();
    ref_setSR_PARAM(&local_4,0xe0);
    bVar1 = ATUII_TIOR3A_B;
    ATUII_TIOR3A_B = bVar1 & 0x8f | 0x60;
    ATUII_GR3B_W = 0;
    bVar1 = ATUII_TIOR3B_B;
    ATUII_TIOR3B_B = bVar1 & 0xf8 | 6;
    ATUII_GR3C_W = 0;
    bVar1 = ATUII_TIOR3B_B;
    ATUII_TIOR3B_B = bVar1 & 0x8f | 0x60;
    ATUII_GR3D_W = 0;
    bVar1 = ATUII_TIOR4A_B;
    ATUII_TIOR4A_B = bVar1 & 0xf8 | 6;
    ATUII_GR4A_W = 0;
    bVar1 = ATUII_TIOR4B_B;
    ATUII_TIOR4B_B = bVar1 & 0x8f | 0x60;
    ATUII_GR4D_W = 0;
    FUN_00002064(local_4);
    FUN_0000b5a0();
    FUN_0000bdbc();
    FUN_00007568();
    FUN_0000ac02();
    FUN_0000c176();
    FUN_00008268();
    FUN_00008f94();
    FUN_0000b290();
    FUN_0001122a();
    FUN_0000d46c();
    FUN_00009f0c(1);
  } while( true );
}


