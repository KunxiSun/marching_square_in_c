#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "marching.h"
#include "check-table.h"

uint8_t *msquare_1bit(uint8_t *input, size_t in_width, size_t in_height, uint8_t threshold)
{
    int i, j;
    uint8_t *data = (uint8_t *)malloc(sizeof(uint8_t) * in_width * in_height);
    for (i = 0; i < in_height; i++)
    {
        for (j = 0; j < in_width; j++)
        {
            data[i * in_width + j] = ((input[i * in_width + j] > threshold) ? 1 : 0); //1 = 0000 0001, 0=0000 0000
        }
    }
    return data;
}

void msquare_detect(uint8_t *data, size_t width, size_t height, uint8_t *segments, size_t segments_length)
{
    int i, j, m;
    int len = 0;
    uint8_t grid[4];
    uint8_t res;
    //uint8_t *local_seg = (uint8_t *)malloc(sizeof(uint8_t) * segments_length);
    for (i = 0; i < height - 2; i += 3)
    {
        for (j = 0; j < width - 2; j += 3)
        {
            res = 0; //initial as 0000 0000

            grid[0] = data[i * width + j];
            grid[1] = data[i * width + j + 2];
            grid[2] = data[(i + 2) * width + j + 2];
            grid[3] = data[(i + 2) * width + j];

            for (m = 0; m < 4; m++)
            {
                res = (res << 1) | grid[m];
            }
            segments[len++] = res;
            //printf("res %d \n", res);
        }
    }
    //segments = local_seg;
}

void msquare_fill(uint8_t *new_image, size_t width, size_t height, uint8_t *segments, size_t seg_length, uint8_t pos_colour, uint8_t neg_colour)
{
    int i, j, m;
    int len = 0;
    //uint8_t *local_ori = (uint8_t *)malloc(sizeof(uint8_t) * in_height * in_width);
    for (i = 0; i < height - 2; i += 3)
    {
        for (j = 0; j < width - 2; j += 3)
        {
            for(m=0;m<9;m++){
                if(cases[segments[len]][m]==1){
                    (new_image[(i+m/3)*width+j+m%3]==1)?(new_image[(i+m/3)*width+j+m%3]=pos_colour):(new_image[(i+m/3)*width+j+m%3]=neg_colour);
                }
            }
            len++;
        }
    }
}