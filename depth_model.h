#ifndef PAPARAZZI_DEPTH_MODEL_H
#define PAPARAZZI_DEPTH_MODEL_H

#ifndef DEPTH_VECTOR_SIZE
#define DEPTH_VECTOR_SIZE 16
#endif

void print_array(float arr[], int size);

void entry(const float tensor_input_1[1][3][520][240], float tensor_79[1][DEPTH_VECTOR_SIZE]);

#endif //PAPARAZZI_DEPTH_MODEL_H