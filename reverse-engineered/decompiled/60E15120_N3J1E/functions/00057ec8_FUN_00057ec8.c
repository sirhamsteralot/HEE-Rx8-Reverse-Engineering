/* ROM address: 0x00057ec8; body bytes: 598; decompiled */

void FUN_00057ec8(void)

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
  
  if (DAT_ffffd228 != '\0') {
    bVar1 = true;
    if (DAT_ffffd229 == '\0') {
      DAT_ffffd229 = DAT_ffffd228;
      local_24 = 0x58;
      ref_setupForUdsResponse_(0x18,&local_24,1);
      DAT_ffffd224 = DAT_ffffd224 + 1;
      if (DAT_ffffd229 == '\x01') {
        sVar3 = FUN_000615c6(0x80,0,&DAT_ffffd1fc);
        local_38 = FUN_0005f8fa();
        if (local_38 != 0) {
          DAT_ffffd22c = 1;
        }
      }
      else if (DAT_ffffd229 == '\x02') {
        local_38 = 0;
        sVar3 = 0;
        uVar7 = 0;
        do {
          cVar5 = FUN_000581ac(uVar7);
          if (cVar5 == '\0') {
            sVar3 = sVar3 + 1;
            if (((uVar7 & 0xffff) == 0) || ((uVar7 & 0xffff) == 1)) {
              local_38 = local_38 + 1;
            }
          }
          uVar7 = uVar7 + 1;
        } while ((uVar7 & 0xffff) < 0x8c);
        if (local_38 != 0) {
          DAT_ffffd22c = 3;
        }
      }
      else {
        sVar3 = 0;
        local_38 = 0;
        DAT_ffffd22c = 0;
      }
      DAT_ffffd22a = (sVar3 - local_38) + DAT_ffffd22c;
      if (0xff < DAT_ffffd22a) {
        DAT_ffffd22a = 0xff;
      }
      local_24 = (undefined1)DAT_ffffd22a;
      ref_setupForUdsResponse_(0x18,&local_24,1);
      DAT_ffffd224 = DAT_ffffd224 + 1;
      if (DAT_ffffd22a == 0) {
        bVar1 = false;
      }
    }
    else {
      uStack_34 = 0;
      do {
        if (DAT_ffffd22c == 0) {
          do {
            if (DAT_ffffd229 == '\x01') {
              uVar7 = (uint)*(short *)(&DAT_ffffd1fc + (uint)DAT_ffffd226 * 2);
            }
            else if (DAT_ffffd229 == '\x02') {
              uVar7 = (uint)(short)DAT_ffffd226;
            }
            else {
              uVar7 = 0;
              bVar1 = false;
            }
            DAT_ffffd226 = DAT_ffffd226 + 1;
          } while ((DAT_ffffd226 < 0x8c) &&
                  ((((uVar7 & 0xffff) == 0 || ((uVar7 & 0xffff) == 1)) ||
                   (cVar5 = FUN_000581ac(uVar7), cVar5 == '\x01'))));
          uVar4 = FUN_0005f950(uVar7);
        }
        else {
          if (DAT_ffffd229 == '\x01') {
            uVar2 = FUN_00067bbc(0);
            iVar6 = FUN_0005f8cc(uVar2);
          }
          else if (DAT_ffffd229 == '\x02') {
            iVar6 = 3 - DAT_ffffd22c;
          }
          else {
            iVar6 = 0;
            bVar1 = false;
          }
          DAT_ffffd22c = DAT_ffffd22c + -1;
          uVar4 = FUN_0005f95a(iVar6);
        }
        local_24 = (undefined1)((ushort)uVar4 >> 8);
        local_23 = (undefined1)uVar4;
        local_22 = 0xff;
        ref_setupForUdsResponse_(0x18,&local_24,3);
        DAT_ffffd224 = DAT_ffffd224 + 3;
        uStack_34 = uStack_34 + 1;
        DAT_ffffd22e = DAT_ffffd22e + 1;
        if (DAT_ffffd22a <= DAT_ffffd22e) {
          bVar1 = false;
        }
      } while ((uStack_34 < 0x20) && (bVar1));
    }
    if (!bVar1) {
      ref_udsResponseRelated__(0x18,(int)DAT_ffffd224);
      FUN_00057e72();
    }
  }
  return;
}


