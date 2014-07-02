#ifndef ITEMS_H
#define ITEMS_H

#include <pthread.h>
#include <stdlib.h>

#define POWER_LARGEST 200
#define MAXLENGTH 100

#define ITEM_key(it) (it->key)

struct settings {
  int num_threads;
  int chunk_size;
  int maxbytes;
};

// initialized elsewhere
extern struct settings settings;
extern pthread_t *pthread_ids;

#ifndef __cplusplus
typedef enum
{
    false = ( 1 == 0 ),
    true = ( ! false )
} bool;
#endif

void setup_thread_ids();
int get_size(int clsid);

#endif 
