/* ROM address: 0x00000170; body bytes: 160; decompiled */

void FUN_00000170(void)

{
  can_enter_reset_mode(&HCAN0_MCR_B);
  HCAN0_TXPR_W = 0;
  HCAN0_TXCR_W = 0;
  HCAN0_TXACK_W = 0xfeff;
  HCAN0_ABACK_W = 0xfeff;
  HCAN0_RXPR_W = 0xffff;
  HCAN0_RFPR_W = 0xffff;
  HCAN0_UMSR_W = 0xffff;
  HCAN0_BCR_W = 0x803e;
  INT_ATU102_IMI10AG(0,1,8,1,0xffffe,1,&HCAN0_MBCR_W,&HCAN0_MBIMR_W,&HCAN0_MD0_1__B,&HCAN0_MC0_1__B)
  ;
  INT_ATU102_IMI10AG(1,0,8,1,0x21,1,&HCAN0_MBCR_W,&HCAN0_MBIMR_W,&HCAN0_MD1_1__B,&HCAN0_MC1_1__B);
  can_exit_reset_mode(&HCAN0_MCR_B);
  HCAN0_IMR_W = 0xfeff;
  HCAN0_LAFMH_W = 0;
  HCAN0_LAFML_W = 0;
  return;
}


