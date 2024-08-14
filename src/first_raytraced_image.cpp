#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>

color ray_color(const Ray& r) {
    Vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}


int main() {
    auto aspect_ratio = 16.00 / 9.0;
    int image_width = 400;

    // Calculate the image heigt and ensure that its at least 1.
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Viewport width less than one are ok since the are real valued;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height);

    // Camera
    auto focal_length = 1.0;
    auto camera_center = Point3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges
    auto viewport_u = Vec3(viewport_width, 0, 0);
    auto viewport_v = Vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel
    auto viewport_upper_left = camera_center - Vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Render

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (size_t line = 0; line < image_height; line++)
    {
        for (size_t coloumn = 0; coloumn < image_width; coloumn++)
        {
            auto pixel_center = line * pixel_delta_u + coloumn * pixel_delta_v + pixel00_loc;
            auto ray_direction = pixel_center - camera_center;

            Ray r(camera_center, ray_direction);
            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.               \n";

    return 0;
}