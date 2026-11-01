/* ROM address: 0x000099b0; body bytes: 134; decompiled */

bool FUN_000099b0(int param_1)

{
  ushort uVar1;
  bool bVar2;
  undefined4 uVar3;
  ushort *puVar4;
  ushort uVar6;
  undefined2 *puVar5;
  undefined2 uVar7;
  
  uVar3 = FUN_00003920(0x90);
  puVar4 = (ushort *)can_mailbox_reg_addr((int)*(char *)(param_1 + 5),&DAT_ffffe406);
  uVar1 = *puVar4;
  uVar6 = can_mailbox_bitmask((int)*(char *)(param_1 + 5));
  bVar2 = (uVar6 & uVar1) != 0;
  if (!bVar2) {
    puVar5 = (undefined2 *)can_mailbox_reg_addr((int)*(char *)(param_1 + 5),&DAT_ffffe40a);
    uVar7 = can_mailbox_bitmask((int)*(char *)(param_1 + 5));
    *puVar5 = uVar7;
    can_mailbox_write_payload((int)*(char *)(param_1 + 5),(int)*(char *)(param_1 + 6),0,
                 *(undefined4 *)(param_1 + 8));
    puVar5 = (undefined2 *)can_mailbox_reg_addr((int)*(char *)(param_1 + 5),&DAT_ffffe406);
    uVar7 = can_mailbox_bitmask((int)*(char *)(param_1 + 5));
    *puVar5 = uVar7;
  }
  FUN_00003934(uVar3);
  return bVar2;
}


