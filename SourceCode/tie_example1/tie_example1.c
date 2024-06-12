#include <stdio.h>
#include <xtensa/tie/tie_example1.h>

int main(void) {
   unsigned char a[10] = {0,0,0,0,0,0,0,0,0,0};
   unsigned char b[10] = {0,1,2,3,4,5,6,7,8,9};
   unsigned char c[10] = {9,8,7,6,5,4,3,2,1,0};
   // necessary for SIMD solution only
   VR *pvra, *pvrb, *pvrc;
   
   int i;

   // source code without TIE speedup
   for (i = 0; i < 10; i++) {
      a[i] = a[i]+b[i]+c[i];
      a[i] = a[i] >> 1;
   }

   // ADD3 fusion
   for (i = 0; i < 10; i++) {
      ADD3(a[i], b[i], c[i]);
      a[i] = a[i] >> 1;
   }


   // ADD3+DIV2 fusion
   for (i = 0; i < 10; i++) {
      ADD3_DIV2(a[i], b[i], c[i]);
   }

   
   // SIMD solution
   pvra = (VR*)a;
   pvrb = (VR*)b;
   pvrc = (VR*)c;
   ADD3_DIV2_SIMD(*pvra, *pvrb, *pvrc);

   for (i = 0; i < 10; i++) {
      printf("%d ", a[i]);
   }
   
   return 0;
}

