#include <stdint.h>
#include <string.h>
#include <assert.h>
#include "../decompiled/rx8_analysis_types.h"
typedef uint16_t ushort; typedef uint32_t uint; typedef uint8_t undefined1;





void original_sort(ushort *param_1,uint param_2)

{
  ushort uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  
  param_2 = param_2 & 0xffff;
  if (1 < param_2) {
    if (param_2 == 2) {
      puVar5 = param_1 + 2;
      if (*puVar5 < *param_1) {
        uVar1 = *param_1;
        uVar2 = *(undefined1 *)(param_1 + 1);
        *param_1 = *puVar5;
        *(undefined1 *)(param_1 + 1) = *(undefined1 *)(param_1 + 3);
        *puVar5 = uVar1;
        *(undefined1 *)(param_1 + 3) = uVar2;
      }
    }
    else {
      iVar6 = 0;
      puVar5 = param_1;
      for (iVar4 = 1; iVar4 < (int)param_2; iVar4 = iVar4 + 1) {
        uVar1 = puVar5[2];
        uVar2 = *(undefined1 *)(puVar5 + 3);
        for (iVar3 = iVar6; (-1 < iVar3 && (uVar1 < param_1[iVar3 * 2])); iVar3 = iVar3 + -1) {
          param_1[(iVar3 + 1) * 2] = param_1[iVar3 * 2];
          *(undefined1 *)(param_1 + (iVar3 + 1) * 2 + 1) = *(undefined1 *)(param_1 + iVar3 * 2 + 1);
        }
        param_1[(iVar3 + 1) * 2] = uVar1;
        *(undefined1 *)(param_1 + (iVar3 + 1) * 2 + 1) = uVar2;
        iVar6 = iVar6 + 1;
        puVar5 = puVar5 + 2;
      }
    }
  }
  return;
}


void rx8_insertion_sort_u16_key_u8_payload(Rx8KeyPayloadRecord *records, uint32_t count)
{
  count &= 0xffffu;
  for (uint32_t insertion_index = 1; insertion_index < count; ++insertion_index) {
    uint16_t pending_key = records[insertion_index].key;
    uint8_t pending_payload = records[insertion_index].payload;
    uint32_t destination_index = insertion_index;
    while (destination_index != 0 && pending_key < records[destination_index - 1].key) {
      records[destination_index].key = records[destination_index - 1].key;
      records[destination_index].payload = records[destination_index - 1].payload;
      --destination_index;
    }
    records[destination_index].key = pending_key;
    records[destination_index].payload = pending_payload;
  }
  /* Padding bytes stay at their original locations, matching the ROM stores. */
}

int main(void) {
 uint32_t seed=917; Rx8KeyPayloadRecord a[64], c[64];
 for(unsigned trial=0;trial<2000;trial++) {
  unsigned count=trial%65;
  for(unsigned i=0;i<64;i++) { seed=seed*1664525u+1013904223u; a[i].key=(uint16_t)(seed%19); a[i].payload=(uint8_t)i; a[i].untouched_padding=(uint8_t)(seed>>24); }
  memcpy(c,a,sizeof a); original_sort((ushort*)a,count); rx8_insertion_sort_u16_key_u8_payload(c,count);
  assert(memcmp(a,c,sizeof a)==0);
 }
 return 0;
}
