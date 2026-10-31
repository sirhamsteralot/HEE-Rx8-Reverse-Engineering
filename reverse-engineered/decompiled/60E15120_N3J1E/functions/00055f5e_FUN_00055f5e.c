/* ROM address: 0x00055f5e; body bytes: 270; decompiled */

void FUN_00055f5e(char param_1)

{
  char cVar2;
  undefined4 uVar1;
  byte *pbVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte local_40;
  byte local_24 [8];
  
  bVar5 = 0xff;
  bVar6 = bVar5;
  bVar7 = bVar5;
  if (param_1 != '\x03') {
    local_40 = 0;
    while( true ) {
      uVar4 = ATUII_TCNT0H_W;
      bVar5 = 0;
      pbVar3 = local_24;
      do {
        *pbVar3 = (byte)uVar4;
        bVar5 = bVar5 + 1;
        uVar4 = uVar4 >> 8;
        pbVar3 = pbVar3 + 1;
      } while (bVar5 < 4);
      cVar2 = FUN_00055e3e(4);
      if (cVar2 == '\0') {
        bVar6 = 0xaa;
        bVar5 = 0x55;
        bVar7 = 0x55;
      }
      else {
        bVar5 = local_24[2] ^ local_24[0];
        bVar6 = local_24[1] ^ local_24[0];
        bVar7 = local_24[3] ^ local_24[0];
      }
      local_40 = local_40 + 1;
      if (0x10 < local_40) break;
      if ((((bVar5 != 0) || (bVar6 != 0)) || (bVar7 != 0)) &&
         (((bVar5 != 0xff || (bVar6 != 0xff)) || (bVar7 != 0xff)))) goto LAB_00056050;
    }
    bVar5 = 0xff;
    bVar6 = bVar5;
    bVar7 = 0xff;
  }
LAB_00056050:
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  DAT_ffffd1d5 = bVar5;
  DAT_ffffd1d6 = bVar6;
  DAT_ffffd1d7 = bVar7;
  DAT_ffffd1d8 = param_1;
  ref_setSR(uVar1);
  return;
}


