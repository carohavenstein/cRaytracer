#include <iostream>
#include "Vec3.h"
#include "Color.h"
#include "Ray.h"

Color ray_color(const Ray r) {
    Vec3 unit_direction = unit_vector(r.direction);
    auto a = 0.5*(unit_direction.y + 1.0);
    return (1.0-a) * Color(0.0, 0.0, 0.0) + a * Color(0.0, 0.0, 1.0);
}

int main() {

    double aspect_ratio = 16.0 / 9.0; // 1.778
    int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = static_cast<int>(image_width / aspect_ratio);
    // condition ? true : false
    image_height = (image_height < 1) ? 1 : image_height; // 1.785

    // Camera
    // distance from eye to viewport
    double focal_length = 1.0;
    // Viewport widths less than one are ok since they are real valued.
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);
    Vec3 camera_center = Point3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    Vec3 viewport_u = Vec3(viewport_width, 0, 0);
    Vec3 viewport_v = Vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    Vec3 pixel_delta_u = viewport_u / image_width;
    Vec3 pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel.
    Vec3 viewport_upper_left = camera_center
                             - Vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    Vec3 pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    // Render

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << "    " << std::flush;
        for (int i = 0; i < image_width; i++) {
            Vec3 pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            Ray r(camera_center, ray_direction);

            Color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
        std::cout << "\n";
    }

    std::clog << "\rDone.                    \n";
}