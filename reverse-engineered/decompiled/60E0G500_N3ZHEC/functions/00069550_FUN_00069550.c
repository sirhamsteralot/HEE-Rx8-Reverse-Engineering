/* ROM address: 0x00069550; body bytes: 146; decompiled */

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
    if ((&DAT_0005f2e4)[(uint)bVar4 * 0xc] == -1) {
      return uVar3;
    }
    iVar1 = (uint)bVar4 * 0xc;
    if ((uint)(byte)(&DAT_0005f2e4)[iVar1] == (param_1 & 0xff)) break;
    bVar4 = bVar4 + 1;
    if (0xfe < bVar4) {
      return uVar3;
    }
  }
  if ((*(uint *)(&DAT_0005f2ec + iVar1) & uVar2) != 0) {
    (*(code *)(&switchD_0005625a::switchdataD_0005f2e8)[(uint)bVar4 * 3])((int)param_2,(int)param_3)
    ;
    return 0;
  }
  return 2;
}


