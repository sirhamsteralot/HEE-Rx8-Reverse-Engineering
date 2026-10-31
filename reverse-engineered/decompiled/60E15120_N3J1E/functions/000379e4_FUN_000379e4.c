/* ROM address: 0x000379e4; body bytes: 626; decompiled */

void FUN_000379e4(void)

{
  undefined4 uVar1;
  char cVar3;
  ushort uVar2;
  int iVar4;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if ((((DAT_ffffc49c != '\x01') && (DAT_ffffc49c != '\x02')) && (DAT_ffffc49c != '\x03')) &&
     (DAT_ffffc49c != '\x04')) goto LAB_00037c9a;
  cVar3 = FUN_0000bed8();
  if (cVar3 == '\0') {
    DAT_ffffc4a0 = 0;
    if (DAT_ffffc4a2 == '\0') {
      FUN_0000be30(0x4c00000);
      DAT_ffffc4a2 = '\x01';
    }
    else if (DAT_ffffc4a3 == '\0') {
      if (DAT_ffffc4a4 == '\x01') {
        DAT_ffffc4a4 = '\0';
      }
      else {
        uVar2 = FUN_0000bdfa((uint)(byte)DAT_ffffc498 * 0x10000 + 0x6000000);
        if (uVar2 != DAT_ffffc49a) {
          if (DAT_ffffc4a5 != '\x01') {
            DAT_ffffc4a5 = '\x01';
            goto LAB_00037aa4;
          }
          DAT_ffffc4a6 = '\x01';
        }
        DAT_ffffc4a5 = '\0';
      }
LAB_00037aa4:
      if (DAT_ffffc4a5 == '\0') {
        if (DAT_ffffc4a6 == '\0') {
          DAT_ffffc498 = (ushort)DAT_ffffc49f * 0x80 + DAT_ffffc48e;
          iVar4 = ((int)(short)DAT_ffffc48e & 0x7fffU) * 2;
          DAT_ffffc49a = (ushort)(byte)(&DAT_ffffc28e)[iVar4] * 0x100 +
                         (ushort)(byte)(&DAT_ffffc28f)[iVar4];
          uVar2 = FUN_0000bdfa((uint)(byte)DAT_ffffc498 * 0x10000 + 0x6000000);
          if (uVar2 != DAT_ffffc49a) {
            FUN_0000be5e((uint)(byte)DAT_ffffc498 * 0x10000 + (uint)DAT_ffffc49a + 0x5000000);
          }
          if (DAT_ffffc49f == 0xff) {
            DAT_ffffc49f = 0;
          }
          else {
            DAT_ffffc49f = 0;
            DAT_ffffc48e = DAT_ffffc48e + 1;
            if (DAT_ffffc490 < DAT_ffffc48e) {
              DAT_ffffc4a3 = '\x01';
            }
          }
        }
        else {
          DAT_ffffc4a1 = 0;
          FUN_0000be30(0x4000000);
          DAT_ffffc4a3 = '\0';
          DAT_ffffc4a2 = '\0';
        }
      }
    }
    else {
      uVar2 = FUN_0000bdfa((uint)(byte)DAT_ffffc498 * 0x10000 + 0x6000000);
      if (uVar2 == DAT_ffffc49a) {
LAB_00037b88:
        DAT_ffffc4a5 = '\0';
      }
      else {
        if (DAT_ffffc4a5 == '\x01') {
          DAT_ffffc4a6 = '\x01';
          goto LAB_00037b88;
        }
        DAT_ffffc4a5 = '\x01';
      }
      if (DAT_ffffc4a5 == '\0') {
        if (DAT_ffffc4a6 == '\0') {
          if (DAT_ffffc49c == '\x01') {
            DAT_ffffc288 = 1;
          }
          else if (DAT_ffffc49c == '\x02') {
            DAT_ffffc289 = 1;
          }
          else if (DAT_ffffc49c == '\x03') {
            DAT_ffffc28a = 1;
          }
          DAT_ffffc49c = '\0';
        }
        DAT_ffffc4a1 = 0;
        FUN_0000be30(0x4000000);
        DAT_ffffc4a3 = '\0';
        DAT_ffffc4a2 = '\0';
      }
    }
  }
  else if ((DAT_ffffc4a0 != 0xff) && (DAT_ffffc4a0 = DAT_ffffc4a0 + 1, 5 < DAT_ffffc4a0)) {
    DAT_ffffc4a6 = '\x01';
    DAT_ffffc4a1 = 0;
    DAT_ffffc4a3 = '\0';
    DAT_ffffc4a2 = '\0';
  }
  if (DAT_ffffc4a6 == '\x01') {
    if (DAT_ffffc49c == '\x01') {
      DAT_ffffc28b = 1;
    }
    else if (DAT_ffffc49c == '\x02') {
      DAT_ffffc28c = 1;
    }
    else if (DAT_ffffc49c == '\x03') {
      DAT_ffffc28d = 1;
    }
    DAT_ffffc49c = '\0';
  }
LAB_00037c9a:
  ref_setSR(uVar1);
  return;
}


