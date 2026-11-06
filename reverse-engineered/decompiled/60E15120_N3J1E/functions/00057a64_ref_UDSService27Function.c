/* [ADDITIONAL SOURCE REVIEW]
 * uds_service_27_security_access [high]: service table record 0x5ebb8 (service 0x27) -> handler; ROM bytes verified; UDS 0x27 (ref_UDSService27Function); seed/key compare lives under it
 */
/* ROM address: 0x00057a64; body bytes: 426; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00057ace) */
/* Unique exact-byte match to related 60E0FC00 function at 00055f34 (426 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint uds_service_27_security_access(short param_1,uint param_2)

{
  uint uVar1;
  char cVar3;
  byte bVar4;
  uint uVar2;
  undefined4 uVar5;
  byte local_30 [4];
  short sStack_2c;
  char cStack_28;
  undefined1 local_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 auStack_20 [8];
  
  param_2 = param_2 & 0xff;
  sStack_2c = param_1;
  if (param_2 != 1) {
    if (param_2 != 0) {
      return param_2;
    }
    uVar2 = FUN_0005494a(0x27);
    return uVar2;
  }
  ref_udsServiceResponse(0x27,local_30,1);
  cStack_28 = FUN_00055e2a();
  uVar2 = FUN_00055eaa();
  if (sStack_2c == 0) {
    uVar5 = 0x12;
  }
  else {
    if (local_30[0] != 0) {
      if ((local_30[0] & 1) == 1) {
        if (sStack_2c == 1) {
          FUN_00055f5e(3);
          uVar1 = FUN_00055e56((int)(char)local_30[0]);
          if ((uVar1 & 0xff) == 3) {
            uVar5 = ref_udsErrorResponse(0x27,0x31);
          }
          else {
            cVar3 = FUN_00055eec((int)cStack_28,uVar2,uVar1);
            if (cVar3 == '\0') {
              if ((uVar2 & 0xff) == (uVar1 & 0xff)) {
                uStack_22 = 0;
                uStack_23 = 0;
                local_24 = 0;
              }
              else {
                FUN_00055f5e(uVar1);
                FUN_00056084(&local_24);
              }
              uVar5 = FUN_00057c0e((int)(char)local_30[0],&local_24,3);
            }
            else {
              uVar5 = ref_udsErrorResponse(0x27,0x31);
            }
          }
        }
        else {
          uVar5 = ref_udsErrorResponse(0x27,0x12);
        }
      }
      else if (sStack_2c == 4) {
        uVar2 = FUN_00056084(&local_24);
        FUN_00055f5e(3);
        if ((uVar2 & 0xff) == 3) {
          uVar5 = ref_udsErrorResponse(0x27,0x22);
        }
        else {
          bVar4 = FUN_00055f4e(uVar2);
          if (bVar4 == local_30[0]) {
            ref_udsServiceResponse(0x27,auStack_20,3);
            cVar3 = FUN_0005609e(uVar2,&local_24,auStack_20);
            if (cVar3 == '\0') {
              FUN_00055ce4(uVar2);
              uVar5 = FUN_00057c0e((int)(char)local_30[0],auStack_20,0);
            }
            else {
              uVar5 = ref_udsErrorResponse(0x27,0x35);
            }
          }
          else {
            uVar5 = ref_udsErrorResponse(0x27,0x22);
          }
        }
      }
      else {
        uVar5 = ref_udsErrorResponse(0x27,0x12);
      }
      goto LAB_00057be6;
    }
    uVar5 = 0x31;
  }
  uVar5 = ref_udsErrorResponse(0x27,uVar5);
LAB_00057be6:
  uVar2 = ref_udsResponseRelated__(0x27,uVar5);
  return uVar2;
}


