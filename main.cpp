#include <iostream>
#include "Vec3.h"
#include "Color.h"
#include "Ray.h"

int main() {
    int columns = 900;
    int rows = 900;

    std::cout << "P3\n" << columns << " " << rows << "\n255\n";
    for (int j = 0; j < rows; j++) {
        std::clog << "\rScanlines remaining: " << (rows - j) << "    " << std::flush;
        for (int i = 0; i < columns; i++) {
            Color pixel_color((float)j/(rows-1),
                              (float)i/(columns-1),
                              1);
            write_color(std::cout, pixel_color);
        }
        std::cout << "\n";
    }

    std::clog << "\rDone.                    \n";
}