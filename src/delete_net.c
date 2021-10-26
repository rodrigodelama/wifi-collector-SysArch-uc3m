#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../incl/sizes.h"
#include"../src/cells.c"
 void delete_net(char net[], cell *cells){
    int counter = 0;
    for(int i = 0; i < c_index){
       if(net == cells[i].ESSID){
           free(cells[i]);
       }
    }
 }