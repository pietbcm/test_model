How to use:

- Copy generated depth model to this folder
- Add the following code at the top:

'''
#include "depth_model.h"
#include <stdio.h>
#include <stdlib.h>

#define CHANNELS 3
#define HEIGHT 520
#define WIDTH 240

void print_array(float arr[], int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%.2f ", arr[i]);
  }
  printf("]\n\n");
}

int main() {
  float *tensor = (float*)malloc(CHANNELS * HEIGHT * WIDTH * sizeof(float));
  if (!tensor) {
      printf("Memory allocation failed\n");
      return 1;
  }

  FILE *file = fopen("test_img.txt", "r");
  for (int i = 0; i < CHANNELS * HEIGHT * WIDTH; i++) {
      fscanf(file, "%f", &tensor[i]);
  }
  fclose(file);

  for (int i = 0; i < 10; i++) {
    printf("%f ", tensor[i]);
  }
  printf("\n");

  float depth_vector[1][DEPTH_VECTOR_SIZE] = {0};
  // const float (*tensor_reshaped)[3][520][240] = (const float (*)[3][520][240])tensor;
  const float tensor_reshaped[1][3][520][240] = {0};

  entry(tensor_reshaped, depth_vector);
  print_array(depth_vector[0], DEPTH_VECTOR_SIZE);

  free(tensor);
  return 0;
}
'''

- Use print_array in the entry function to print some stuff

- Compile using gcc and run it:
'''
gcc depth_model.c
./a.out
'''