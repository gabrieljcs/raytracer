//
//  hitable.h
//  raytracer
//
//  Created by Gabriel de Jesus on 31/12/19.
//  Copyright © 2019 Gabriel de Jesus. All rights reserved.
//

#ifndef hitable_h
#define hitable_h

#include "ray.h"

struct hit_record {
    float t;
    vec3 p;
    vec3 normal;
};

class hitable {
public:
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
}


#endif /* hitable_h */
