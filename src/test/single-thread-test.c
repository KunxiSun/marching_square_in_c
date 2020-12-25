#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "../src/marching.h"

#define WIDTH (9000)
#define HEIGHT (9000)
#define THRESHOLD (100)

struct thread_data
{
    uint8_t *img;
    size_t width;
    size_t height;

    uint8_t threshold;

    uint8_t neg_color;
    uint8_t pos_color;
};

/**
* Return an array generated by rand number
*/
uint8_t *makeImage(int width, int height)
{
    uint8_t *img = malloc(sizeof(uint8_t) * height * width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            img[i * width + j] = rand() % 255;
        }
    }
    return img;
}

/**
 * The thread function, has 3 steps:
 * 1. generate a bit image by the given image
 * 2. generate the segmentation from the bit image
 * 3. generate a image that is overwrite by the segmentation
*/
void* thread_func(void *arg)
{
    struct thread_data *data = (struct thread_data *)arg;

    //First step
    uint8_t *bit_img = msquare_1bit(data->img, data->width, data->height, data->threshold);

    //initial segments and set all value as 0
    size_t segment_len = (data->width) * (data->height) / 9;
    uint8_t *segments = (uint8_t *)malloc(sizeof(uint8_t) * segment_len);
    memset(segments, 0, segment_len);

    //Second step
    msquare_detect(bit_img, data->width, data->height, segments, segment_len);

    //Third step
    msquare_fill(bit_img, data->width, data->height, segments, segment_len, 2, 2);

    free(bit_img);
    free(segments);
    return NULL;
}

int main()
{
    struct thread_data *data = (struct thread_data *)malloc(sizeof(struct thread_data));
    data->img = makeImage(WIDTH, HEIGHT);
    data->neg_color = 2;
    data->pos_color = 2;
    data->threshold = THRESHOLD;
    data->height = HEIGHT;
    data->width = WIDTH;

    pthread_t threads[1];

    pthread_create(&threads[0], NULL, thread_func, (void*)data);

    pthread_join(threads[0], NULL);

    free(data->img);
    free(data);
    return 0;
}