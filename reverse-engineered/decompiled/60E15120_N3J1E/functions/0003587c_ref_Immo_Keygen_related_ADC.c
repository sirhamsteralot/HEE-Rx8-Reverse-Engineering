/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003587c; body bytes: 218; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00035f9c (218 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_Immo_Keygen_related_ADC(void)

{
  short sVar1;
  ushort snapshot_DAT_ffff9f1c;
  ushort snapshot_DAT_ffff9f1e;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  snapshot_DAT_ffff9f1e = DAT_ffff9f1e;
  snapshot_DAT_ffff9f1c = DAT_ffff9f1c;
  sVar1 = DAT_ffff9f00;
  iVar6 = (int)(short)DAT_ffff9f1e;
  uVar4 = ref_readValue_32bit_ADDRESS_VAL(&DAT_ffff8674,0);
  DAT_ffffc223 = (char)uVar4 + (char)snapshot_DAT_ffff9f1c + DAT_ffffc223;
  if ((int)~(uint)DAT_ffffc218 < (int)(uVar4 >> 0x10)) {
    if (DAT_ffffc21a == 0xffff) {
      DAT_ffffc223 = DAT_ffffc223 + 1;
    }
    DAT_ffffc21a = DAT_ffffc21a + 1;
  }
  puVar5 = (undefined4 *)((uVar4 >> 0x10) + (int)(short)DAT_ffffc218 + iVar6);
  if ((int)~(uint)DAT_ffffc21a < (int)((uVar4 & 0xffff00) >> 8)) {
    DAT_ffffc223 = DAT_ffffc223 + 1;
  }
  DAT_ffffc218 = sVar1 * 0x100 + (snapshot_DAT_ffff9f1c & 0xff) ^ (ushort)puVar5;
  DAT_ffffc21a = ~(snapshot_DAT_ffff9f1c * 0x100 + (snapshot_DAT_ffff9f1e & 0xff) ^
                  (short)((uVar4 & 0xffff00) >> 8) + DAT_ffffc21a + sVar1);
  DAT_ffffc223 = (byte)snapshot_DAT_ffff9f1e ^ DAT_ffffc223;
  DAT_ffffc208 = (uint)DAT_ffffc218 * 0x10000 + (uint)DAT_ffffc21a;
  if (DAT_ffffc208 == 0) {
    puVar5 = &DAT_ffffc26c;
    DAT_ffffc208 = DAT_ffffc26c | DAT_ffffc270;
  }
  return puVar5;
}


