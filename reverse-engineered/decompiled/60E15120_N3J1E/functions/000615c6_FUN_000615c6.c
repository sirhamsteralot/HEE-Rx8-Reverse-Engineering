/* ROM address: 0x000615c6; body bytes: 366; decompiled */

uint FUN_000615c6(char param_1,char param_2,int param_3)

{
  ushort uVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  
  uVar3 = dtc_master_current_index_ffff8900._0_2_;
  uVar4 = 0;
  uVar5 = 0;
  do {
    if (uVar5 != uVar3) {
      bVar2 = (&DAT_ffff87b6)[uVar5 * 0x10];
      uVar1 = (&dtc_master_table_21_ffff87b0)[uVar5 * 8];
      if (((param_2 == '\0') ||
          ((param_2 == '\x01' && ((&CAL_DTC_0300_Enable_Disable_1_1129)[uVar1] == '\x01')))) ||
         ((param_2 == '\x02' && ((&DAT_0007e704)[uVar1] == '\x01')))) {
        puVar6 = (ushort *)((uVar4 & 0xffff) * 2 + param_3);
        if (param_1 == '\0') {
          if (bVar2 == 0) {
            *puVar6 = uVar1;
            uVar4 = uVar4 + 1;
          }
        }
        else if (param_1 == '`') {
          if ((bVar2 != 0) && (bVar2 < 0x40)) {
            *puVar6 = uVar1;
            uVar4 = uVar4 + 1;
          }
        }
        else if (param_1 == -0x80) {
          if ((bVar2 & 0x80) == 0x80) {
            *puVar6 = uVar1;
            uVar4 = uVar4 + 1;
          }
        }
        else if (param_1 == -0x40) {
          if (bVar2 == 0xc0) {
            *puVar6 = uVar1;
            uVar4 = uVar4 + 1;
          }
        }
        else if (param_1 == -0x3f) {
          if (bVar2 == 0xc1) {
            *puVar6 = uVar1;
            uVar4 = uVar4 + 1;
          }
        }
        else if (param_1 == 'P') {
          if (bVar2 == 0x50) {
            *puVar6 = uVar1;
            uVar4 = uVar4 + 1;
          }
        }
        else if (param_1 == -0x10) {
          if (((bVar2 != 0) && (bVar2 < 0x40)) || ((bVar2 & 0x80) == 0x80)) {
            *puVar6 = uVar1;
            uVar4 = uVar4 + 1;
          }
        }
        else if (((param_1 == 'p') && (0x80 < bVar2)) && (bVar2 < 0xc0)) {
          *puVar6 = uVar1;
          uVar4 = uVar4 + 1;
        }
      }
    }
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 0x15);
  return uVar4;
}


