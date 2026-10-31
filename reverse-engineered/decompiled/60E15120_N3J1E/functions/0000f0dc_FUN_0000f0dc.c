/* ROM address: 0x0000f0dc; body bytes: 376; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000f0e0 (376 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000f0dc(int param_1,int param_2)

{
  bool bVar1;
  byte bVar3;
  undefined4 uVar2;
  undefined1 uVar4;
  byte *pbVar5;
  undefined1 uStack_24;
  
  uStack_24 = 0;
  if ((*(char *)(param_1 + 7) == '\0') && (*(char *)(param_1 + 2) == '\x01')) {
    for (pbVar5 = (byte *)(param_1 + 0x10); pbVar5 < (byte *)(param_1 + 0x58);
        pbVar5 = pbVar5 + 0x18) {
      if (((pbVar5[1] == 1) && ((&injector_channel_enable_flag_ffffa017)[(uint)*pbVar5 * 0x18] == '\0')) ||
         ((pbVar5[1] == 0 && ((pbVar5[0x14] == 0 && (param_2 < *(int *)(pbVar5 + 0xc))))))) {
        *(undefined1 *)(param_1 + 7) = 1;
        break;
      }
    }
  }
  bVar1 = false;
  if (*(char *)(param_1 + 7) == '\0') {
    for (pbVar5 = (byte *)(param_1 + 0x10); pbVar5 < (byte *)(param_1 + 0x58);
        pbVar5 = pbVar5 + 0x18) {
      if (pbVar5[1] == 1) {
        if (pbVar5[0x14] == 0) {
          *(undefined4 *)(pbVar5 + 4) = *(undefined4 *)(pbVar5 + 8);
          FUN_000084c6((int)(char)*pbVar5,*(undefined4 *)(pbVar5 + 8));
        }
        else {
          if ((&injector_channel_enable_flag_ffffa017)[(uint)*pbVar5 * 0x18] == '\0') {
            FUN_000084c6((int)(char)*pbVar5,0);
            bVar3 = 2;
          }
          else {
            injector_channel_disable((int)(char)*pbVar5);
            bVar3 = 0;
          }
          pbVar5[1] = bVar3;
        }
      }
      else if ((pbVar5[1] == 0) && (pbVar5[0x14] == 0)) {
        if (param_2 - *(int *)(pbVar5 + 0xc) < 0x1e0000) {
          if ((*(char *)(param_1 + 2) == '\0') || (*(int *)(pbVar5 + 0xc) <= param_2)) {
            *(undefined4 *)(pbVar5 + 4) = *(undefined4 *)(pbVar5 + 8);
            uVar2 = FUN_0000fa0e(0);
            FUN_00008344((int)(char)*pbVar5,uVar2,*(undefined4 *)(pbVar5 + 4));
            pbVar5[1] = 1;
            bVar1 = true;
          }
          else {
            pbVar5[1] = 2;
          }
        }
        else {
          uStack_24 = 1;
        }
      }
    }
    uVar4 = 1;
  }
  else {
    uVar4 = 2;
  }
  *(undefined1 *)(param_1 + 2) = uVar4;
  if (bVar1) {
    FUN_0000f9f2();
    FUN_0000fa06();
  }
  *(undefined1 *)(param_1 + 6) = uStack_24;
  return;
}


