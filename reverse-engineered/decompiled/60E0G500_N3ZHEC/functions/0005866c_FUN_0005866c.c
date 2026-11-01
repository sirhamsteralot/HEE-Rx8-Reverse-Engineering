/* ROM address: 0x0005866c; body bytes: 598; decompiled */

void FUN_0005866c(void)

{
  bool bVar1;
  short sVar3;
  undefined4 uVar2;
  undefined2 uVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  short local_38;
  ushort uStack_34;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  
  if (DAT_ffffd264 != '\0') {
    bVar1 = true;
    if (DAT_ffffd265 == '\0') {
      DAT_ffffd265 = DAT_ffffd264;
      local_24 = 0x58;
      FUN_000688c8(0x18,&local_24,1);
      DAT_ffffd260 = DAT_ffffd260 + 1;
      if (DAT_ffffd265 == '\x01') {
        sVar3 = FUN_00061d6a(0x80,0,&DAT_ffffd238);
        local_38 = FUN_0006009e();
        if (local_38 != 0) {
          DAT_ffffd268 = 1;
        }
      }
      else if (DAT_ffffd265 == '\x02') {
        local_38 = 0;
        sVar3 = 0;
        uVar7 = 0;
        do {
          cVar5 = FUN_00058950(uVar7);
          if (cVar5 == '\0') {
            sVar3 = sVar3 + 1;
            if (((uVar7 & 0xffff) == 0) || ((uVar7 & 0xffff) == 1)) {
              local_38 = local_38 + 1;
            }
          }
          uVar7 = uVar7 + 1;
        } while ((uVar7 & 0xffff) < 0x8c);
        if (local_38 != 0) {
          DAT_ffffd268 = 3;
        }
      }
      else {
        sVar3 = 0;
        local_38 = 0;
        DAT_ffffd268 = 0;
      }
      DAT_ffffd266 = (sVar3 - local_38) + DAT_ffffd268;
      if (0xff < DAT_ffffd266) {
        DAT_ffffd266 = 0xff;
      }
      local_24 = (undefined1)DAT_ffffd266;
      FUN_000688c8(0x18,&local_24,1);
      DAT_ffffd260 = DAT_ffffd260 + 1;
      if (DAT_ffffd266 == 0) {
        bVar1 = false;
      }
    }
    else {
      uStack_34 = 0;
      do {
        if (DAT_ffffd268 == 0) {
          do {
            if (DAT_ffffd265 == '\x01') {
              uVar7 = (uint)*(short *)(&DAT_ffffd238 + (uint)DAT_ffffd262 * 2);
            }
            else if (DAT_ffffd265 == '\x02') {
              uVar7 = (uint)(short)DAT_ffffd262;
            }
            else {
              uVar7 = 0;
              bVar1 = false;
            }
            DAT_ffffd262 = DAT_ffffd262 + 1;
          } while ((DAT_ffffd262 < 0x8c) &&
                  ((((uVar7 & 0xffff) == 0 || ((uVar7 & 0xffff) == 1)) ||
                   (cVar5 = FUN_00058950(uVar7), cVar5 == '\x01'))));
          uVar4 = FUN_000600f4(uVar7);
        }
        else {
          if (DAT_ffffd265 == '\x01') {
            uVar2 = FUN_00068360(0);
            iVar6 = FUN_00060070(uVar2);
          }
          else if (DAT_ffffd265 == '\x02') {
            iVar6 = 3 - DAT_ffffd268;
          }
          else {
            iVar6 = 0;
            bVar1 = false;
          }
          DAT_ffffd268 = DAT_ffffd268 + -1;
          uVar4 = FUN_000600fe(iVar6);
        }
        local_24 = (undefined1)((ushort)uVar4 >> 8);
        local_23 = (undefined1)uVar4;
        local_22 = 0xff;
        FUN_000688c8(0x18,&local_24,3);
        DAT_ffffd260 = DAT_ffffd260 + 3;
        uStack_34 = uStack_34 + 1;
        DAT_ffffd26a = DAT_ffffd26a + 1;
        if (DAT_ffffd266 <= DAT_ffffd26a) {
          bVar1 = false;
        }
      } while ((uStack_34 < 0x20) && (bVar1));
    }
    if (!bVar1) {
      FUN_000550ca(0x18,(int)DAT_ffffd260);
      FUN_00058616();
    }
  }
  return;
}


