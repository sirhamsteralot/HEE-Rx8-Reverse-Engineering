/* ROM address: 0x00038cc0; body bytes: 460; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00038daa) */
/* WARNING: Removing unreachable block (ram,0x00038dba) */
/* WARNING: Removing unreachable block (ram,0x00038dc6) */
/* WARNING: Removing unreachable block (ram,0x00038dd6) */
/* WARNING: Removing unreachable block (ram,0x00038df8) */
/* WARNING: Removing unreachable block (ram,0x00038de4) */
/* WARNING: Removing unreachable block (ram,0x00038dfa) */
/* WARNING: Removing unreachable block (ram,0x00038e0e) */
/* WARNING: Removing unreachable block (ram,0x00038e1a) */
/* WARNING: Removing unreachable block (ram,0x00038e30) */
/* WARNING: Removing unreachable block (ram,0x00038e58) */
/* WARNING: Removing unreachable block (ram,0x00038e3e) */

int FUN_00038cc0(ushort param_1,byte param_2)

{
  byte bVar1;
  undefined4 uVar2;
  char cVar5;
  int iVar3;
  undefined2 uVar4;
  uint uVar6;
  int iVar7;
  ushort uStack_38;
  
  uVar2 = FUN_00003920(0x10);
  iVar7 = 0;
  cVar5 = FUN_0000bed8();
  if ((cVar5 == '\x01') && (cVar5 = FUN_0000bed8(), cVar5 == '\x01')) {
    iVar7 = 1;
  }
  if (iVar7 == 0) {
    iVar3 = (uint)param_2 + (uint)param_1 + -1;
    DAT_ffffc504 = (ushort)((int)(iVar3 + (uint)(iVar3 < 0)) >> 1);
    uStack_38 = (ushort)((int)(uint)param_1 >> 1);
    DAT_ffffc502 = uStack_38;
    for (; uStack_38 <= DAT_ffffc504; uStack_38 = uStack_38 + 1) {
      uVar4 = FUN_0000bdfa((uint)(byte)uStack_38 * 0x10000 + 0x6000000);
      bVar1 = (byte)((ushort)uVar4 >> 8);
      uVar6 = (int)(short)uStack_38 << 1;
      (&DAT_ffffc2fe)[uVar6 & 0xffff] = bVar1;
      (&DAT_ffffc3fe)[uVar6 & 0xffff] = ~bVar1;
      (&DAT_ffffc2ff)[uVar6 & 0xffff] = (byte)uVar4;
      *(byte *)((uVar6 & 0xffff) - 0x3c01) = ~(byte)uVar4;
    }
  }
  FUN_00003934(uVar2);
  return iVar7;
}


