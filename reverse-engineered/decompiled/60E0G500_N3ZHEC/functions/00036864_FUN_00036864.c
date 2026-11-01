/* ROM address: 0x00036864; body bytes: 218; decompiled */

undefined4 * FUN_00036864(void)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  uVar3 = DAT_ffff9f1e;
  uVar2 = DAT_ffff9f1c;
  sVar1 = DAT_ffff9f00;
  iVar6 = (int)(short)DAT_ffff9f1e;
  uVar4 = FUN_0003eb24(&DAT_ffff869c,0);
  DAT_ffffc293 = (char)uVar4 + (char)uVar2 + DAT_ffffc293;
  if ((int)~(uint)DAT_ffffc288 < (int)(uVar4 >> 0x10)) {
    if (DAT_ffffc28a == 0xffff) {
      DAT_ffffc293 = DAT_ffffc293 + 1;
    }
    DAT_ffffc28a = DAT_ffffc28a + 1;
  }
  puVar5 = (undefined4 *)((uVar4 >> 0x10) + (int)(short)DAT_ffffc288 + iVar6);
  if ((int)~(uint)DAT_ffffc28a < (int)((uVar4 & 0xffff00) >> 8)) {
    DAT_ffffc293 = DAT_ffffc293 + 1;
  }
  DAT_ffffc288 = sVar1 * 0x100 + (uVar2 & 0xff) ^ (ushort)puVar5;
  DAT_ffffc28a = ~(uVar2 * 0x100 + (uVar3 & 0xff) ^
                  (short)((uVar4 & 0xffff00) >> 8) + DAT_ffffc28a + sVar1);
  DAT_ffffc293 = (byte)uVar3 ^ DAT_ffffc293;
  DAT_ffffc278 = (uint)DAT_ffffc288 * 0x10000 + (uint)DAT_ffffc28a;
  if (DAT_ffffc278 == 0) {
    puVar5 = &DAT_ffffc2dc;
    DAT_ffffc278 = DAT_ffffc2dc | DAT_ffffc2e0;
  }
  return puVar5;
}


