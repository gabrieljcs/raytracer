//
//  hitablelist.h
//  raytracer
//
//  Created by Gabriel de Jesus on 31/12/19.
//  Copyright © 2019 Gabriel de Jesus. All rights reserved.
//

#ifndef hitablelist_h
#define hitablelist_h

#include "hitable.h"

class hitable_list: public hitable {
public:
    hitable_list() {}
    hitable_list(hitable **l, int n) {
        list = l;
        list_size = n;
    }
}


#endif /* hitablelist_h */
