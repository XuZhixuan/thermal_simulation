#include <iostream>

#include "constant.h"
#include "Matrix.h"
#include "Chunk.h"

int main()
{
    using std::cin;

    Matrix material;
    int x_length, y_length;

    cin >> x_length >> y_length;

    InitMatrix(material, (x_length / X_DELTA + 1), (y_length / Y_DELTA + 1));

    getchar();

    DestroyMatrix(material);

    return 0;
}
