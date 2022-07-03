#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}
#include <stdio.h>
#include <string.h>

#include <estia-image.h>
#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension (char *source_path){
    int width;
    int height;
    int channel;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel);
    printf("dimension: %d, %d", width, height);

}

void first_pixel(char *source_path){
    int width;
    int height;
    int channel;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel);
    printf("first_pixel: %d, %d, %d ", data[0], data[1], data[2]);
}

void tenth_pixel(char *source_path){
    int width;
    int height;
    int channel;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel);
    printf("tenth_pixel: %d, %d, %d ", data[27], data[28], data[29]);
}

void second_line(char *source_path){
    int width;
    int height;
    int channel;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel);
    printf("second_line: %d, %d, %d ", data[3*width], data[3*width+1], data[3*width+2]);
}

void print_pixel(pixelRGB pixel_rgb){
     printf("print_pixel (%d,%d) : %d,%d,%d", pixel_rgb.y, pixel_rgb.x, pixel_rgb.R, pixel_rgb.G, pixel_rgb.B);
}

void max_pixel(char *source_path){
    int width;
    int height;
    int channel;
    unsigned char *data;
    int max, i, j, sum, max_x = 0, max_y = 0;
    read_image_data(source_path, &data, &width, &height, &channel);
    max = get_pixel(data, width, height, channel, 0, 0).R + get_pixel(data, width, height, channel, 0, 0).G + get_pixel(data, width, height, channel, 0, 0).B; 
    for (i = 0; i < width; i++){
        for (j = 0; j < height; j++){
            sum = get_pixel(data, width, height, channel, i, j).R + get_pixel(data, width, height, channel, i, j).G + get_pixel(data, width, height, channel, i, j).B;
            if (sum > max){
                max = sum;
                max_x = i;
                max_y = j;
            }
        }
    }
    printf("max_pixel (%d, %d): %d, %d, %d ", max_y, max_x, get_pixel(data, width, height, channel, max_x, max_y).R, get_pixel(data, width, height, channel, max_x, max_y).G, get_pixel(data, width, height, channel, max_x, max_y).B);
}

void min_pixel(char *source_path){
    int width;
    int height;
    int channel;
    unsigned char *data;
    int min, i, j, tmp, min_x = 0, min_y = 0;
    read_image_data(source_path, &data, &width, &height, &channel);
    min = get_pixel(data, width, height, channel, 0, 0).R + get_pixel(data, width, height, channel, 0, 0).G + get_pixel(data, width, height, channel, 0, 0).B; 
    for (i = 0; i < height; i++){
        for (j = 0; j < width; j++){
            tmp = get_pixel(data, width, height, channel, i, j).R + get_pixel(data, width, height, channel, i, j).G + get_pixel(data, width, height, channel, i, j).B;
            if (tmp < min){
                min = tmp;
                min_x = i;
                min_y = j;
            }
        }
    }
    printf("min_pixel (%d, %d): %d, %d, %d ", min_y, min_x, get_pixel(data, width, height, channel, min_x, min_y).R, get_pixel(data, width, height, channel, min_x, min_y).G, get_pixel(data, width, height, channel, min_x, min_y).B);
}

void max_component(char *source_path, int component){
    int width;
    int height;
    int channel;
    unsigned char *data;
    int max, i, j, tmp, max_x = 0, max_y = 0;
    read_image_data(source_path, &data, &width, &height, &channel);
    if (component == 'R'){
        max = get_pixel(data, width, height, channel, 0, 0).R; 
        for (i = 0; i < height; i++){
            for (j = 0; j < width; j++){
                tmp = get_pixel(data, width, height, channel, i, j).R;
                if (tmp > max){
                    max = tmp;
                    max_x = i;
                    max_y = j;
                }
            }
        }
        printf("max_component %c (%d, %d): %d", component, max_y, max_x, max);
    }
    if (component == 'G'){
        max = get_pixel(data, width, height, channel, 0, 0).G; 
        for (i = 0; i < height; i++){
            for (j = 0; j < width; j++){
                tmp = get_pixel(data, width, height, channel, i, j).G;
                if (tmp > max){
                    max = tmp;
                    max_x = i;
                    max_y = j;
                }
            }
        }
        printf("max_component %c (%d, %d): %d", component, max_y, max_x, max);
    }
    if (component == 'B'){
        max = get_pixel(data, width, height, channel, 0, 0).B; 
        for (i = 0; i < height; i++){
            for (j = 0; j < width; j++){
                tmp = get_pixel(data, width, height, channel, i, j).B;
                if (tmp > max){
                    max = tmp;
                    max_x = i;
                    max_y = j;
                }
            }
        }
        printf("max_component %c (%d, %d): %d", component, max_y, max_x, max);
    }
}

void min_component(char *source_path, int component){
    int width;
    int height;
    int channel;
    unsigned char *data;
    int min, i, j, tmp, min_x = 0, min_y = 0;
    read_image_data(source_path, &data, &width, &height, &channel);
    if (component == 'R'){
        min = get_pixel(data, width, height, channel, 0, 0).R; 
        for (i = 0; i < height; i++){
            for (j = 0; j < width; j++){
                tmp = get_pixel(data, width, height, channel, i, j).R;
                if (tmp < min){
                    min = tmp;
                    min_x = i;
                    min_y = j;
                }
            }
        }
        printf("min_component %c (%d, %d): %d", component, min_y, min_x, min);
    }
    if (component == 'G'){
        min = get_pixel(data, width, height, channel, 0, 0).G; 
        for (i = 0; i < height; i++){
            for (j = 0; j < width; j++){
                tmp = get_pixel(data, width, height, channel, i, j).G;
                if (tmp < min){
                    min = tmp;
                    min_x = i;
                    min_y = j;
                }
            }
        }
        printf("min_component %c (%d, %d): %d", component, min_y, min_x, min);
    }
    if (component == 'B'){
        min = get_pixel(data, width, height, channel, 0, 0).B; 
        for (i = 0; i < height; i++){
            for (j = 0; j < width; j++){
                tmp = get_pixel(data, width, height, channel, i, j).B;
                if (tmp < min){
                    min = tmp;
                    min_x = i;
                    min_y = j;
                }
            }
        }
        printf("min_component %c (%d, %d): %d", component, min_y, min_x, min);
    }
}

void color_gray_luminance(char *source_path){
    int width;
    int height;
    int channel;
    unsigned char *data;
    int i;
    read_image_data(source_path, &data, &width, &height, &channel);
    for(i = 0; i < width*height; i++){
        data[i*channel] = 0.21 * data[i*channel] + 0.72 * data[i*channel + 1] + 0.07 * data[i*channel + 2];
        data[i*channel + 1] = data[i*channel];
        data[i*channel + 2] = data[i*channel];
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_red(char *source_path){
    int width;
    int height;
    int channel;
    unsigned char *data;
    int i;
    read_image_data(source_path, &data, &width, &height, &channel);
    for(i = 0; i < width*height; i++){
        data[i*channel + 1] = 0;
        data[i*channel + 2] = 0;
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_green(char *source_path){
    int width;
    int height;
    int channel;
    unsigned char *data;
    int i;
    read_image_data(source_path, &data, &width, &height, &channel);
    for(i = 0; i < width*height; i++){
        data[i*channel] = 0;
        data[i*channel + 2] = 0;
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_blue(char *source_path){
    int width;
    int height;
    int channel;
    unsigned char *data;
    int i;
    read_image_data(source_path, &data, &width, &height, &channel);
    for(i = 0; i < width*height; i++){
        data[i*channel] = 0;
        data[i*channel + 1] = 0;
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_gray(char *source_path){
    int width;
    int height;
    int channel;
    unsigned char *data;
    int i;
    read_image_data(source_path, &data, &width, &height, &channel);
    for(i = 0; i < width*height; i++){
        data[i*channel] = (data[i*channel] + data[i*channel + 1] + data[i*channel + 2]) / 3;
        data[i*channel + 1] = data[i*channel];
        data[i*channel + 2] = data[i*channel];
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_invert(char *source_path){
    int width;
    int height;
    int channel;
    unsigned char *data;
    int i;
    read_image_data(source_path, &data, &width, &height, &channel);
    for(i = 0; i < width*height; i++){
        data[i*channel] = 255 - data[i*channel];
        data[i*channel + 1] = 255 - data[i*channel + 1];
        data[i*channel + 2] = 255 - data[i*channel + 2];
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_desaturate(char *source_path){
    int width;
    int height;
    int channel;
    unsigned char *data;
    int i;
    read_image_data(source_path, &data, &width, &height, &channel);
    for(i = 0; i < width*height; i++){
        data[i*channel] = (max_valeur(max_valeur(data[i*channel], data[i*channel + 1]), data[i*channel + 2]) + min_valeur(min_valeur(data[i*channel], data[i*channel + 1]), data[i*channel + 2])) / 2;
        data[i*channel + 1] = data[i*channel];
        data[i*channel + 2] = data[i*channel];
    }
    write_image_data("image_out.bmp", data, width, height);
}
       
}
