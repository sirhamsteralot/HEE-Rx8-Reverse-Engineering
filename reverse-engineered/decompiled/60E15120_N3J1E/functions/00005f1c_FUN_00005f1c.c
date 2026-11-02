/* ROM address: 0x00005f1c; body bytes: 218; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005f1c (218 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 os_post_message(uint param_1,undefined4 *param_2)

{
  byte bVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 uVar7;
  undefined *puVar8;
  undefined4 *puVar9;
  
  uVar7 = 0;
  iVar5 = (param_1 & 0xffff) * 8;
  puVar8 = (&tbl_os_queue_records_0000d74c)[(param_1 & 0xffff) * 2];
  sVar2 = *(short *)(&DAT_0000d750 + iVar5);
  bVar1 = (&DAT_0000d752)[iVar5];
  uVar3 = sh_raise_interrupt_mask_return_previous(0xe0);
  if (bVar1 < (byte)(&DAT_ffff9306)[(param_1 & 0xffff) * 3]) {
    uVar7 = 2;
  }
  else {
    iVar5 = os_wake_posted_task((int)sVar2);
    if (iVar5 == 0) {
      iVar5 = (param_1 & 0xffff) * 3;
      (&DAT_ffff9306)[iVar5] = (&DAT_ffff9306)[iVar5] + '\x01';
      puVar9 = (undefined4 *)(puVar8 + (uint)(byte)(&queue_state_base_ffff9304)[iVar5] * 0x14);
      iVar5 = 5;
      do {
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        iVar5 = iVar5 + -1;
        *puVar9 = uVar4;
        puVar9 = puVar9 + 1;
      } while (iVar5 != 0);
      pbVar6 = &queue_state_base_ffff9304 + (param_1 & 0xffff) * 3;
      *pbVar6 = *pbVar6 + 1;
      if (bVar1 <= *pbVar6) {
        (&queue_state_base_ffff9304)[(param_1 & 0xffff) * 3] = 0;
      }
    }
    else {
      uVar7 = 1;
      ref_calledLots((int)sVar2);
    }
  }
  ref_setSR(uVar3);
  return uVar7;
}


