/* ROM address: 0x00068c58; body bytes: 116; decompiled */

void uds_request_schedule_service_task(int param_1)

{
  uint local_14;
  uint uStack_10;
  uint local_c;
  
  FUN_000692c6((int)DAT_ffffde28);
  FUN_0006936a(1,0x28);
  local_14 = (uint)DAT_ffffde26;
  uStack_10 = (uint)DAT_ffffde22;
  local_c = (uint)(param_1 != 0x7df);
  DAT_ffffde35 = DAT_ffffde26;
  DAT_ffffde27 = 0;
  DAT_ffffde31 = DAT_ffffde31 & 0xfb | 0x40;
  thunk_FUN_000552d0((int)(char)DAT_ffffde26);
  FUN_00009630(2,0,&local_14);
  return;
}


