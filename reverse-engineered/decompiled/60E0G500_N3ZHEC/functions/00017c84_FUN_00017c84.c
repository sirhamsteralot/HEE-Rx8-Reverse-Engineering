/* ROM address: 0x00017c84; body bytes: 96; decompiled */

void FUN_00017c84(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x10);
  DAT_ffffa964 = DAT_ffffa964 + 1;
  if (7 < DAT_ffffa964) {
    FUN_00017dbc();
    FUN_00017278();
    FUN_00017468();
    FUN_0001750e();
    FUN_000176ba();
    FUN_00016d7c();
    FUN_000177d0();
    DAT_ffffa964 = 0;
  }
  FUN_00017fc6();
  FUN_00003934(uVar1);
  return;
}


