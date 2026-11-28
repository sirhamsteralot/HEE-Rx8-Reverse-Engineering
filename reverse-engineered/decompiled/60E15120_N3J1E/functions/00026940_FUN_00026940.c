/* [ADDITIONAL SOURCE REVIEW]
 * misfire_sector_ring_copy [high]: 8-float copy: DAT_ffffb664..0xffffb680 = DAT_ffffa390..0xffffa3ac (sector-period ring written by crank_edge_period_update 0xcf96). 66-byte body, all mov.l pairs; called from 0x287aa.
 * RAM 0xffffb664 misfire_sector_ring_copy (float[8]): Copy of the crank sector-period ring 0xffffa390..0xffffa3ac made by misfire_sector_ring_copy 0x26940; read by the deviation math 0x28198/0x2842c/0x28118 (cells 0xffffb664..0xffffb680).
 */
/* ROM address: 0x00026940; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00027264 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void misfire_sector_ring_copy(void)

{
  misfire_sector_ring_copy_ffffb664 = sector_period_ring_ffffa390;
  DAT_ffffb668 = DAT_ffffa394;
  DAT_ffffb66c = DAT_ffffa398;
  DAT_ffffb670 = DAT_ffffa39c;
  DAT_ffffb674 = DAT_ffffa3a0;
  DAT_ffffb678 = DAT_ffffa3a4;
  DAT_ffffb67c = DAT_ffffa3a8;
  DAT_ffffb680 = DAT_ffffa3ac;
  return;
}


