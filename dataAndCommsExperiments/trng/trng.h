/*
 * trng.h
 *
 *  Created on: Dec 1, 2025
 *      Author: artyo
 */

#ifndef TRNG_H_
#define TRNG_H_

#ifdef DEBUG
#include "stdio.h"
#define TRNG_DBG(...) printf(__VA_ARGS__); //my own printf!
#endif /* debug */
#define TRNG_ADDR 0x48021800 //addr for rng vals!

//#define TRNG_ADDR 0x48021800 //addr for rng vals!
//#define TRNG_ADDR 0x48021800 //addr for rng vals!
//#define TRNG_ADDR 0x48021800 //addr for rng vals!

#endif /* TRNG_H_ */
