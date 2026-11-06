/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffd4e4 dtc_transition_state_array (uint8[0x8c]): Per-slot transition state written by 0x60062 on mode 1/2/4.
 */
/* ROM address: 0x00060062; body bytes: 272; decompiled */

uint FUN_00060062(uint param_1,uint param_2,short param_3)

{
  byte bVar1;
  char cVar3;
  uint uVar2;
  int iVar4;
  uint uVar5;
  
  iVar4 = (int)(short)*(ushort *)(&DAT_0007df42 + (param_1 & 0xffff) * 2);
  uVar5 = (uint)*(ushort *)(&DAT_0007df42 + (param_1 & 0xffff) * 2);
  bVar1 = (&DAT_0007e32a)[uVar5];
  param_2 = param_2 & 0xff;
  if (param_2 == 2) {
    cVar3 = ref_faultEnableStatus2(iVar4,0x10);
    if (cVar3 == '\0') {
      cVar3 = FUN_00061800(iVar4);
      param_2 = 0;
      if (cVar3 != '\0') {
        FUN_00061b28(iVar4);
        FUN_000602c8(iVar4,0);
        (&dtc_transition_state_array_ffffd4e4)[uVar5] = 2;
        param_2 = uVar5;
      }
    }
    else {
      param_2 = (uint)(byte)(&dtc_transition_state_array_ffffd4e4)[uVar5];
      if ((byte)(&dtc_transition_state_array_ffffd4e4)[uVar5] != 2) {
        FUN_00060190(param_1,0x10,0);
        (&dtc_transition_state_array_ffffd4e4)[uVar5] = 2;
        param_2 = uVar5;
      }
    }
  }
  else if (param_2 == 4) {
    param_2 = (uint)(byte)(&dtc_transition_state_array_ffffd4e4)[uVar5];
    if (((byte)(&dtc_transition_state_array_ffffd4e4)[uVar5] != 4) &&
       (((bVar1 == 3 || (bVar1 == 1)) || (param_2 = (uint)bVar1, bVar1 == 2)))) {
      FUN_00060190(param_1,0x11,0);
      (&dtc_transition_state_array_ffffd4e4)[uVar5] = 4;
      param_2 = uVar5;
    }
  }
  else if ((param_2 == 1) &&
          ((((&dtc_transition_state_array_ffffd4e4)[uVar5] != '\x01' || (bVar1 == 1)) ||
           (param_2 = (uint)bVar1, bVar1 == 2)))) {
    uVar2 = FUN_0005fb68(iVar4);
    param_2 = uVar2 & 0xff;
    if ((uVar2 & 0xff) == 0) {
      FUN_00060190(param_1,0x20,(int)param_3);
      (&dtc_transition_state_array_ffffd4e4)[uVar5] = 1;
      param_2 = uVar5;
    }
  }
  return param_2;
}


