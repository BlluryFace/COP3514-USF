#include <stdio.h>
#include <string.h>
struct color{
    int red;
    int green;
    int blue;
};

struct color make_color(int red, int green, int blue){
    struct color c;
    if (red <= 255 && red >= 0){
        c.red = red;
    } else if (red > 255){
        c.red = 255;
    } else if (red < 0){
        c.red = 0;
    }
    if (green <= 255 && green >= 0){
        c.green = green;
    } else if (green > 255){
        c.green = 255;
    } else if (green < 0){
        c.green = 0;
    }
    if (blue <= 255 && blue >= 0){
        c.blue = blue;
    } else if (blue > 255){
        c.blue = 255;
    } else if (blue < 0){
        c.blue = 0;
    }
    return c;
}
int main() {
    struct color magenta = {255,0,225};
    printf("%d, %d, %d\n", magenta.red,magenta.green,magenta.blue);
    struct color color2;
    printf("Input new color code: ");
    int red;
    int green;
    int blue;
    scanf("%d, %d, %d", &red, &green, &blue);
    color2 = make_color(red, green, blue);
    printf("%d, %d, %d\n", color2.red,color2.green,color2.blue);
}