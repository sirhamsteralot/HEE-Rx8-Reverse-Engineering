/* ROM address: 0x0000109c; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000109c (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_resetOBDCAN_(void)

{
  FUN_00001e94(&HCAN0_MCR_B);
  FUN_00001ed0(0xe,1,8,0,0x7e0,1,&HCAN0_MBCR_W,&HCAN0_MBIMR_W,&HCAN0_MD14_1__B,&HCAN0_MC14_1__B);
  FUN_00001ed0(0xf,0,8,0,0x7e8,1,&HCAN0_MBCR_W,&HCAN0_MBIMR_W,&HCAN0_MD15_1__B,&HCAN0_MC15_1__B);
  FUN_00001eb2(&HCAN0_MCR_B);
  return;
}


