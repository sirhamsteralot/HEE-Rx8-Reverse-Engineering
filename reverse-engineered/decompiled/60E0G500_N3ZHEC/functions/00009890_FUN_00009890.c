/* ROM address: 0x00009890; body bytes: 262; decompiled */

undefined4 can_rx_copy_mailbox_to_buffer(int param_1)

{
  ushort uVar1;
  ushort *puVar2;
  ushort uVar5;
  undefined4 uVar3;
  undefined2 *puVar4;
  undefined2 uVar6;
  undefined4 uVar7;
  uint uVar8;
  
  puVar2 = (ushort *)can_mailbox_reg_addr((int)*(char *)(param_1 + 5),&DAT_ffffe40e);
  uVar1 = *puVar2;
  uVar5 = can_mailbox_bitmask((int)*(char *)(param_1 + 5));
  if ((uVar5 & uVar1) == 0) {
    uVar7 = 1;
  }
  else {
    uVar3 = FUN_00003920(0x90);
    puVar4 = (undefined2 *)can_mailbox_reg_addr((int)*(char *)(param_1 + 5),&DAT_ffffe41a);
    uVar6 = can_mailbox_bitmask((int)*(char *)(param_1 + 5));
    *puVar4 = uVar6;
    can_mailbox_read_payload((int)*(char *)(param_1 + 5),(int)*(char *)(param_1 + 6),0,
                 *(undefined4 *)(param_1 + 8));
    uVar7 = 2;
    uVar8 = 0;
    do {
      puVar2 = (ushort *)can_mailbox_reg_addr((int)*(char *)(param_1 + 5),&DAT_ffffe41a);
      uVar1 = *puVar2;
      uVar5 = can_mailbox_bitmask((int)*(char *)(param_1 + 5));
      if ((uVar5 & uVar1) == 0) {
        uVar7 = 0;
        break;
      }
      puVar4 = (undefined2 *)can_mailbox_reg_addr((int)*(char *)(param_1 + 5),&DAT_ffffe41a);
      uVar6 = can_mailbox_bitmask((int)*(char *)(param_1 + 5));
      *puVar4 = uVar6;
      can_mailbox_read_payload((int)*(char *)(param_1 + 5),(int)*(char *)(param_1 + 6),0,
                   *(undefined4 *)(param_1 + 8));
      uVar8 = uVar8 + 1;
    } while (uVar8 < 5);
    puVar4 = (undefined2 *)can_mailbox_reg_addr((int)*(char *)(param_1 + 5),&DAT_ffffe40e);
    uVar6 = can_mailbox_bitmask((int)*(char *)(param_1 + 5));
    *puVar4 = uVar6;
    FUN_00003934(uVar3);
  }
  return uVar7;
}


