#include <cstdlib>
#include <cstdio>

typedef float Point[3];

void projection(Point corners[8], const unsigned int width, const unsigned int height);

int main()
{
    Point corners[8] = {
        {1, -1, -5},
        {1, -1, -3},
        {1, 1, -5},
        {1, 1, -3},
        {-1, -1, -5},
        {-1, -1, -3},
        {-1, 1, -5},
        {-1, 1, -3}};

    const unsigned int image_width = 512, image_height = 512;

    projection(corners, image_width, image_height);

    return 0;
}

// 沿着z轴投影;归一化后坐标与canvas的位置无关
void projection(Point corners[8], const unsigned int width, const unsigned int height)
{
    float aspect_ratio = (float)width / height;
    for (int i = 0; i < 8; i++)
    {
        float x_proj = corners[i][0] / -corners[i][2];
        float y_proj = corners[i][1] / -corners[i][2] * aspect_ratio;
        float x_proj_remap = (x_proj + 1) / 2;
        float y_proj_remap = (y_proj + 1) / 2;
        float x_proj_pix = x_proj_remap * width;
        float y_proj_pix = y_proj_remap * height;
        printf("Corner: %d x:%f y:%f\n", i, x_proj_pix, y_proj_pix);
    }
}