/* ROM address: 0x00068dac; body bytes: 146; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006769c (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 uds_service_dispatch_table_scan(uint param_1,short param_2,char param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  byte bVar4;
  
  uVar3 = 1;
  uVar2 = FUN_00004308(param_1,1);
  bVar4 = 0;
  while( true ) {
    if ((&tbl_uds_service_dispatch_0005eb40)[(uint)bVar4 * 0xc] == -1) {
      return uVar3;
    }
    iVar1 = (uint)bVar4 * 0xc;
    if ((uint)(byte)(&tbl_uds_service_dispatch_0005eb40)[iVar1] == (param_1 & 0xff)) break;
    bVar4 = bVar4 + 1;
    if (0xfe < bVar4) {
      return uVar3;
    }
  }
  if ((*(uint *)(&DAT_0005eb48 + iVar1) & uVar2) != 0) {
    (*(code *)(&switchD_00055ab6::switchdataD_0005eb44)[(uint)bVar4 * 3])((int)param_2,(int)param_3)
    ;
    return 0;
  }
  return 2;
}


