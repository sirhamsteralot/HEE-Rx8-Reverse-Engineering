/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_boot_param_read [high]: 19 calls to 0x37ef0 (pool 0x35a48) reading indexed params into RAM 0xffffc268-0xffffc282 (dest pools 0x35a48-0x35a88: 0x35a48=0x37ef0, 0x35a4c=0xffffc268, 0x35a50=0xffffc26c, 0x35a54=0xffffc270, ... 0x35a7c=0xffffc27f etc.); indexes 0,2,6,10,0xc,0xd,0xe,0xf,0x10,0x16,0x18,0x12,0x13,0x14,0x1a,0x1b,0x1c,0x1d,0x1e. Called from 0x349e4 (callgraph), itself called from the boot fan-out 0x1102a. Inherited ref_getDataFromE2RAM confirmed as the boot parameter-block read.
 * RAM 0xffffc268 e2ram_param_block (uint8[32]): Boot parameter block 0xffffc268-0xffffc282 filled by 0x3599c via 0x37ef0 (19 indexed fields); source cells for the write dispatch 0x35a8c.
 */
/* ROM address: 0x0003599c; body bytes: 164; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000360bc (164 bytes). Names prefixed ref_
   are inherited hypotheses. */

void e2ram_boot_param_read(void)

{
  e2ram_cached_byte_read(0,&e2ram_param_block_ffffc268,1);
  e2ram_cached_byte_read(2,&DAT_ffffc26c,4);
  e2ram_cached_byte_read(6,&DAT_ffffc270,4);
  e2ram_cached_byte_read(10,&inferred_ram_c274_ffffc274_ffffc274,1);
  e2ram_cached_byte_read(0xc,&DAT_ffffc275,1);
  e2ram_cached_byte_read(0xd,&DAT_ffffc276,1);
  e2ram_cached_byte_read(0xe,&inferred_ram_c1d3_ffffc1d3_ffffc1d3,1);
  e2ram_cached_byte_read(0xf,&DAT_ffffc277,1);
  e2ram_cached_byte_read(0x10,&inferred_ram_c1d2_ffffc1d2_ffffc1d2,1);
  e2ram_cached_byte_read(0x16,&DAT_ffffc27a,2);
  e2ram_cached_byte_read(0x18,&DAT_ffffc27c,2);
  e2ram_cached_byte_read(0x12,&inferred_ram_c1d4_ffffc1d4_ffffc1d4,1);
  e2ram_cached_byte_read(0x13,&DAT_ffffc278,1);
  e2ram_cached_byte_read(0x14,&DAT_ffffc279,1);
  e2ram_cached_byte_read(0x1a,&DAT_ffffc27e,1);
  e2ram_cached_byte_read(0x1b,&DAT_ffffc27f,1);
  e2ram_cached_byte_read(0x1c,&DAT_ffffc280,1);
  e2ram_cached_byte_read(0x1d,&DAT_ffffc281,1);
  e2ram_cached_byte_read(0x1e,&DAT_ffffc282,1);
  return;
}


