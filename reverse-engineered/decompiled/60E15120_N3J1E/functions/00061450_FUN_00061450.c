/* ROM address: 0x00061450; body bytes: 342; decompiled */

int FUN_00061450(char param_1,char param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  do {
    if (uVar3 != dtc_master_current_index_ffff8900._0_2_) {
      bVar1 = (&DAT_ffff87b6)[uVar3 * 0x10];
      if (((param_2 == '\0') ||
          ((param_2 == '\x01' &&
           ((&CAL_DTC_0300_Enable_Disable_1_1129)[(ushort)(&dtc_master_table_21_ffff87b0)[uVar3 * 8]] == '\x01'))))
         || ((param_2 == '\x02' && ((&DAT_0007e704)[(ushort)(&dtc_master_table_21_ffff87b0)[uVar3 * 8]] == '\x01')))
         ) {
        if (param_1 == '\0') {
          if (bVar1 == 0) {
            iVar2 = iVar2 + 1;
          }
        }
        else if (param_1 == '`') {
          if ((bVar1 != 0) && (bVar1 < 0x40)) {
            iVar2 = iVar2 + 1;
          }
        }
        else if (param_1 == -0x80) {
          if ((bVar1 & 0x80) == 0x80) {
            iVar2 = iVar2 + 1;
          }
        }
        else if (param_1 == -0x40) {
          if (bVar1 == 0xc0) {
            iVar2 = iVar2 + 1;
          }
        }
        else if (param_1 == -0x3f) {
          if (bVar1 == 0xc1) {
            iVar2 = iVar2 + 1;
          }
        }
        else if (param_1 == 'P') {
          if (bVar1 == 0x50) {
            iVar2 = iVar2 + 1;
          }
        }
        else if (param_1 == -0x10) {
          if (((bVar1 != 0) && (bVar1 < 0x40)) || ((bVar1 & 0x80) == 0x80)) {
            iVar2 = iVar2 + 1;
          }
        }
        else if (((param_1 == 'p') && (0x80 < bVar1)) && (bVar1 < 0xc0)) {
          iVar2 = iVar2 + 1;
        }
      }
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x15);
  return iVar2;
}


