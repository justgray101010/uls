#include "uls.h"

int mx_getmaxlinks(t_file **files) {
    int i = 0;
    int max_size = 0;

    while (files[i] != NULL) {
        if (max_size < mx_strlen(files[i]->links))
            max_size = mx_strlen(files[i]->links);
        i++;
    }
    return max_size;
}

int mx_getmaxuser(t_file **files) {
    int i = 0;
    int max_size = 0;

    while(files[i] != NULL) {
        if (max_size < mx_strlen(files[i]->user))
            max_size = mx_strlen(files[i]->user);
        i++;
    }
    return max_size;
}

int mx_getmaxgroup(t_file **files) {
	int i = 0;
	int max_size = 0;

    while (files[i] != NULL) {
        if (max_size < mx_strlen(files[i]->group)) {
            max_size = mx_strlen(files[i]->group);
        } 
        i++; 
    } 
    return max_size;   
}

int mx_getmaxsize(t_file **files) {
	int i = 0;
	int max_size = 0;

    while (files[i] != NULL) {
        if (max_size < mx_strlen(files[i]->size)) {
        	if (mx_get_char_index(files[i]->size, ',') > 0){
        		if (max_size <= 8) {
        			max_size = 8;
                }
            }
            else
            	max_size = mx_strlen(files[i]->size);
        } 
        i++; 
    } 
    return max_size;   
}


int mx_getmaxtime(t_file **files) {
	int i = 0;
	int max_size = 0;

    while (files[i] != NULL) {
        if (max_size < mx_strlen(files[i]->stime))
            max_size = mx_strlen(files[i]->stime);
        i++; 
    } 
    return max_size;   
}
