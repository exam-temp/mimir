#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstring>

#include "item.hpp"
#include "rounder.hpp"
#include "common.hpp"

#define DO_SANITYCHECKS 1

/******* Implementation details: ********/
/* T+B-1 is the top bucket
 * T is the bottom bucket
 * B is the number of buckets

  We age elements at stackdistance between 0 and the average stack distance that is hit
  Because of that the elements are not evenly distributed amongst the bins
  However, if we age everything the bins are all used
*/


void rounder::Hit(item *it, int dist /* =-1 */) {
  ++hits;
  ++requests;
  statistics_hit(0, it);
}

void rounder::Miss(const char *key) {
  ++misses;
  ++requests;
  // calculate hash value 
  statistics_miss(0, key);
}

// set in the cache
void rounder::Set(item *it) {
  statistics_set(0, it);
}

// this item was evicted from the main cache
void rounder::Evict(item *it) {
  statistics_evict(0, it);
}


void rounder::printStatistics() {
  fprintf(stderr, "hits = %d, misses = %d\n", hits, misses);
  if (requests > 0) {
    assert ( hits + misses == requests );
    fprintf(stderr, "hitratio = %.5f\n", (hits + 0.0) / requests);
  }
}
  
