/* ROM address: 0x000389cc; body bytes: 626; decompiled */

void FUN_000389cc(void)

{
  undefined4 uVar1;
  char cVar3;
  ushort uVar2;
  int iVar4;
  
  uVar1 = FUN_00003920(0x10);
  if ((((DAT_ffffc50c != '\x01') && (DAT_ffffc50c != '\x02')) && (DAT_ffffc50c != '\x03')) &&
     (DAT_ffffc50c != '\x04')) goto LAB_00038c82;
  cVar3 = FUN_0000bed8();
  if (cVar3 == '\0') {
    DAT_ffffc510 = 0;
    if (DAT_ffffc512 == '\0') {
      FUN_0000be30(0x4c00000);
      DAT_ffffc512 = '\x01';
    }
    else if (DAT_ffffc513 == '\0') {
      if (DAT_ffffc514 == '\x01') {
        DAT_ffffc514 = '\0';
      }
      else {
        uVar2 = FUN_0000bdfa((uint)(byte)DAT_ffffc508 * 0x10000 + 0x6000000);
        if (uVar2 != DAT_ffffc50a) {
          if (DAT_ffffc515 != '\x01') {
            DAT_ffffc515 = '\x01';
            goto LAB_00038a8c;
          }
          DAT_ffffc516 = '\x01';
        }
        DAT_ffffc515 = '\0';
      }
LAB_00038a8c:
      if (DAT_ffffc515 == '\0') {
        if (DAT_ffffc516 == '\0') {
          DAT_ffffc508 = (ushort)DAT_ffffc50f * 0x80 + DAT_ffffc4fe;
          iVar4 = ((int)(short)DAT_ffffc4fe & 0x7fffU) * 2;
          DAT_ffffc50a = (ushort)(byte)(&DAT_ffffc2fe)[iVar4] * 0x100 +
                         (ushort)(byte)(&DAT_ffffc2ff)[iVar4];
          uVar2 = FUN_0000bdfa((uint)(byte)DAT_ffffc508 * 0x10000 + 0x6000000);
          if (uVar2 != DAT_ffffc50a) {
            FUN_0000be5e((uint)(byte)DAT_ffffc508 * 0x10000 + (uint)DAT_ffffc50a + 0x5000000);
          }
          if (DAT_ffffc50f == 0xff) {
            DAT_ffffc50f = 0;
          }
          else {
            DAT_ffffc50f = 0;
            DAT_ffffc4fe = DAT_ffffc4fe + 1;
            if (DAT_ffffc500 < DAT_ffffc4fe) {
              DAT_ffffc513 = '\x01';
            }
          }
        }
        else {
          DAT_ffffc511 = 0;
          FUN_0000be30(0x4000000);
          DAT_ffffc513 = '\0';
          DAT_ffffc512 = '\0';
        }
      }
    }
    else {
      uVar2 = FUN_0000bdfa((uint)(byte)DAT_ffffc508 * 0x10000 + 0x6000000);
      if (uVar2 == DAT_ffffc50a) {
LAB_00038b70:
        DAT_ffffc515 = '\0';
      }
      else {
        if (DAT_ffffc515 == '\x01') {
          DAT_ffffc516 = '\x01';
          goto LAB_00038b70;
        }
        DAT_ffffc515 = '\x01';
      }
      if (DAT_ffffc515 == '\0') {
        if (DAT_ffffc516 == '\0') {
          if (DAT_ffffc50c == '\x01') {
            DAT_ffffc2f8 = 1;
          }
          else if (DAT_ffffc50c == '\x02') {
            DAT_ffffc2f9 = 1;
          }
          else if (DAT_ffffc50c == '\x03') {
            DAT_ffffc2fa = 1;
          }
          DAT_ffffc50c = '\0';
        }
        DAT_ffffc511 = 0;
        FUN_0000be30(0x4000000);
        DAT_ffffc513 = '\0';
        DAT_ffffc512 = '\0';
      }
    }
  }
  else if ((DAT_ffffc510 != 0xff) && (DAT_ffffc510 = DAT_ffffc510 + 1, 5 < DAT_ffffc510)) {
    DAT_ffffc516 = '\x01';
    DAT_ffffc511 = 0;
    DAT_ffffc513 = '\0';
    DAT_ffffc512 = '\0';
  }
  if (DAT_ffffc516 == '\x01') {
    if (DAT_ffffc50c == '\x01') {
      DAT_ffffc2fb = 1;
    }
    else if (DAT_ffffc50c == '\x02') {
      DAT_ffffc2fc = 1;
    }
    else if (DAT_ffffc50c == '\x03') {
      DAT_ffffc2fd = 1;
    }
    DAT_ffffc50c = '\0';
  }
LAB_00038c82:
  FUN_00003934(uVar1);
  return;
}


