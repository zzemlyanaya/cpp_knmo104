//
// Created by zzemlyanaya on 02.03.2022.
//

#include "entities.h"
#include <fstream>

#pragma once

Resort* read(ifstream&, int&);

void write(ofstream&, int&, Resort*);

void doMagic(int&, Resort*);
