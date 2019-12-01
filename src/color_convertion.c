/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Convert color modes
*/

#include <math.h>
#include <SFML/Graphics.h>

static sfColor decide_hsb(float hue, float chroma, float m, float x);

sfColor hsb_to_rgb(float const hue, float const saturation,
                float const brightness, unsigned char const opacity)
{
    float chroma = saturation * brightness;
    float m = brightness - chroma;
    float x = chroma * (1.0 - fabs(fmod(hue / 60.0, 2) - 1.0));
    sfColor color = decide_hsb(hue, chroma, m, x);

    color.a = opacity;
    return (color);
}

static sfColor decide_hsb(float hue, float chroma, float m, float x)
{
    switch ((int)hue / 60) {
    case 0:
        return (sfColor){(chroma + m) * 255.0, (x + m) * 255.0, m * 255.0, 255};
    case 1:
        return (sfColor){(x + m) * 255.0, (chroma + m) * 255.0, m * 255.0, 255};
    case 2:
        return (sfColor){m * 255.0, (chroma + m) * 255.0, (x + m) * 255.0, 255};
    case 3:
        return (sfColor){m * 255.0, (x + m) * 255.0, (chroma + m) * 255.0, 255};
    case 4:
        return (sfColor){(x + m) * 255.0, m * 255.0, (chroma + m) * 255.0, 255};
    case 5:
    case 6:
        return (sfColor){(chroma + m) * 255.0, m * 255.0, (x + m) * 255.0, 255};
    default:
        return (sfColor){m, m, m, 255};
    }
}