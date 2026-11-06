/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffd458 dtc_eval_state_array (uint8[0x8c]): Per-slot eval state (1/2/4) written by 0x5ff5a; read by 0x60478.
 * RAM 0xffffd3c2 dtc_eval_state_cache (uint8[0x8c]): Per-fault-id cached eval-state argument written by 0x5ff5a.
 */
/* ROM address: 0x0005ff5a; body bytes: 218; decompiled */

int FUN_0005ff5a(uint param_1,char param_2)

{
  ushort uVar1;
  uint uVar2;
  char cVar3;
  ushort uVar4;
  
  uVar1 = *(ushort *)(&DAT_0007df42 + (param_1 & 0xffff) * 2);
  if (param_2 != (&dtc_eval_state_cache_ffffd3c2)[param_1 & 0xffff]) {
    (&dtc_eval_state_cache_ffffd3c2)[param_1 & 0xffff] = param_2;
    uVar4 = *(ushort *)(&DAT_0007e06e + (uint)uVar1 * 4);
    if ((param_2 == '\x02') || (param_2 == '\x04')) {
      uVar2 = (int)(char)(&DAT_0007e070)[(uint)uVar1 * 4] & 0xf0;
    }
    else if (param_2 == '\x01') {
      uVar2 = (int)(char)(&DAT_0007e070)[(uint)uVar1 * 4] & 0xf;
    }
    else {
      uVar2 = 0;
    }
    cVar3 = param_2;
    if ((((uVar2 != 0x10) && (uVar2 != 1)) && (uVar2 != 0x40)) && (uVar2 != 4)) {
      if ((uVar2 == 0x20) || (uVar2 == 2)) {
        while (cVar3 != '\0') {
          if ((*(ushort *)(&DAT_0007df42 + (uint)uVar4 * 2) != uVar1) || (0x95 < uVar4))
          goto LAB_0006002e;
          uVar2 = (uint)uVar4;
          uVar4 = uVar4 + 1;
          if ((&dtc_eval_state_cache_ffffd3c2)[uVar2] != param_2) {
            cVar3 = '\0';
          }
        }
        goto LAB_0006003c;
      }
      cVar3 = '\0';
    }
LAB_0006002e:
    if (cVar3 != '\0') {
      (&dtc_eval_state_array_ffffd458)[uVar1] = cVar3;
    }
  }
LAB_0006003c:
  return (int)(char)(&dtc_eval_state_array_ffffd458)[uVar1];
}


