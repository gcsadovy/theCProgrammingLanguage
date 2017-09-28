#include <stdio.h>


//linear serach
int lsearch(int key, int array[], int size)
{
  for (int i = 0; i < size, i++) {
    if(array[i] == key) {
      return i;
    }
  }
  return -1;
}

//second version
void *lsearch(void *key, void *base, int n, int elemsize)
{
  for (int i = 0; i < n; i++) {
    void *elemAddr = (char *)base + i * elemsize;
    if (memcmp(key, elemAddr, elemsize == 0) {
	return elemAddr;
      }
      
