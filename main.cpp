//
//  main.cpp
//  raytracer
//
//  Created by Gabriel de Jesus on 27/12/19.
//  Copyright © 2019 Gabriel de Jesus. All rights reserved.
//

#include <iostream>
#include "ray.h"

float hit_sphere(const vec3& center, float radius, const ray& r) {
    vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = 2.0*dot(oc, r.direction());
    float c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - 4*a*c;
    if (discriminant < 0)
        return -1.0;
    else
        return (-b - sqrt(discriminant) ) / (2.0*a);
}

vec3 color(const ray& r) {
    float t = hit_sphere(vec3(0, 0, -1), 0.5, r);
    if (t > 0.0) {
        vec3 N = unit_vector(r.point_at_parameter(t) - vec3(0, 0, -1));
        return 0.5*vec3(N.x() + 1, N.y() + 1, N.z() + 1);
    }
    vec3 unit_direction = unit_vector(r.direction());
    t = 0.5*(unit_direction.y() + 1.0);
    return (1.0 - t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
}

int main(int argc, const char * argv[]) {
    /*
    P3
    3 2
    255
    # The part above is the header
    # "P3" means this is a RGB color image in ASCII
    # "3 2" is the width and height of the image in pixels
    # "255" is the maximum value for each color
    # The part below is image data: RGB triplets
    255   0   0 //red
    0   255   0 // green
    0   0   255 // blue
    255   255   0 //yellow
    255   255   255 //white
    0   0   0 //black
     */
    
    // PPM I/O
    int nx = 200;
    int ny = 100;
    
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);
    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical);
            vec3 col = color(r);
            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);
            
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
    
    
    return 0;
}
