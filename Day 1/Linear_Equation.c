#include <stdio.h>

int main()
{

    int x[] = {1, 2, 3, 4};
    int y[] = {2, 3, 4, 5};
    float c, m, Y, xy_bar, x_bar, y_bar, x_y_bar, x2_bar, f, x_bar2;
    float sum = 0.0;
    int b = 0, d = 0, e = 0;

    int x_in;
    printf("Enter your value: \n");
    scanf("%d", &x_in);

    for (int i = 0; i <= 3; i++)
    {
        int a = x[i] * y[i];
        sum = sum + a;
    }
    xy_bar = sum / 4.0;

    for (int i = 0; i <= 3; i++)
    {
        b = b + x[i];
        d = d + y[i];
    }
    x_bar = b / 4.0;
    y_bar = d / 4.0;
    x_y_bar = x_bar * y_bar;

    for (int i = 0; i <= 3; i++)
    {
        e = e + (x[i] * x[i]);
    }
    x2_bar = e / 4.0;
    f = b / 4.0;
    x_bar2 = f * f;

    m = (xy_bar - x_y_bar) / (x2_bar - x_bar2);
    c = y_bar - (m * x_bar);

    Y = (m * x_in) + c;

    printf("Predicted Output: \n");
    printf("%0.2f", Y);

    return 0;
}
