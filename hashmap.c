#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) {
    int i = hash(key,map->capacity);
    
    if(map->buckets[i] == NULL || map->buckets[i]->key == NULL)
    {
        map->buckets[i] = createPair(key,value);
    }
    else {
        while (map->buckets[i]->key != NULL && is_equal(map->buckets[i]->key,key) != 1){
            i++;
            if(i == map->capacity)
                i = 0;
        }
        if(map->buckets[i]->key != NULL)
        {
            map->buckets[i]->value = value;
        }
        else{
            map->buckets[i] = createPair(key,value);
        }
        
    }
    map->current = i;
    (map->size)++;

}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) {
    struct HashMap* newMap = (HashMap *) malloc(sizeof(HashMap));
    newMap->capacity = capacity;
    newMap->current = -1;
    newMap->buckets = (Pair **) calloc(capacity,sizeof(Pair *));
    newMap->size = 0;
    
    return newMap;
}

void eraseMap(HashMap * map,  char * key) {    


}

Pair * searchMap(HashMap * map,  char * key) {   


    return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
