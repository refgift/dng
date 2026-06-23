// dng 
// (C) Copyright 2026 Larry B. Daniel Atlanta, Ga.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <sched.h>
#include <sys/resource.h>
#include <string.h>
#include "danger.h"

#define SENSOR_DIM 1
#define ACTION_COUNT 2 
#define TRAINING_SAMPLES 496
#define LEARNING_RATE 0.05
#define EPOCHS 15

int rnd(){
	static int r;
	asm("1: pause; rdrand %0; jnc 1":"=r"(r));
	return r;
}

typedef enum {
    ACTION_FALSE,
    ACTION_TRUTH
} Action;

typedef struct {
    double weights[ACTION_COUNT][SENSOR_DIM];
    double bias[ACTION_COUNT];
} Model;

typedef struct {
    double v[SENSOR_DIM];
} SensorVec;

double random_double(double low, double high)
{
    return low + (high - low) * rnd();
}

static double randd(double a, double b) {

	return random_double(a,b);
}

void model_init(Model *m) {
	m->weights[0][0]=w1;
	m->weights[1][0]=w2;
	m->bias[0]=b1;
	m->bias[1]=b2;
}

// "Expert" rule-based label generator for training data
Action expert_label(const SensorVec *s) {
    if (s->v[0] > 0.8 ) return ACTION_TRUTH;
    return ACTION_FALSE;
}

void simulate_sensor(SensorVec *s) {
    s->v[0] = (double) (rnd() );
}

const char* action_name(Action a) {
    switch (a) {
        case ACTION_TRUTH: return "DANGER";
        case ACTION_FALSE:    return "FALSE";
    }
    return "UNKNOWN";
}

int main(int argc, char ** argv) {
    Model model;
    model_init(&model);
    static bool quiet;
 
    int quit=0;

    if (argv[1]!=NULL&&strcmp(argv[1],"-q")==0) quiet=true;
    else quiet=false;


   // PREDICTION PHASE (fixed model, no updates)
   
    setpriority(0,0,-19);
   
        SensorVec s;
	simulate_sensor(&s);
        Action a = expert_label(&s);
	if  (a==ACTION_TRUTH) {
		if (!quiet)  printf("%s\n", "DANGER");
 	       if(!quiet){
  	              fflush(stdout);
   	     }
	}
	asm("pause");
   
   return 0;
}
