/* [ADDITIONAL SOURCE REVIEW]
 * immo_random_seed_gen [high]: ref_Immo_Keygen_related_ADC (unique_exact_bytes to 60E0FC00 0x35f9c). Builds 32-bit seed DAT_ffffc208 from ADC read (ref_readValue_32bit_ADDRESS_VAL(&DAT_ffff8674,0)), timer cells 0xffff9f00/9f1c/9f1e and running counters c218/c21a/c223; if result 0 falls back to c26c|c270.
 * RAM 0xffffc208 immo_random_seed (u32): built from ADC 0xffff8674 + timers 0xffff9f00/9f1c/9f1e + counters c218/c21a/c223
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003587c; body bytes: 218; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00035f9c (218 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * immo_random_seed_gen(void)

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
  immo_random_seed_ffffc208 = (uint)DAT_ffffc218 * 0x10000 + (uint)DAT_ffffc21a;
  if (immo_random_seed_ffffc208 == 0) {
    puVar5 = &immo_key_reg_a_ffffc26c;
    immo_random_seed_ffffc208 = immo_key_reg_a_ffffc26c | immo_key_reg_b_ffffc270;
  }
  return puVar5;
}


