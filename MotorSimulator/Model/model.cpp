#include "model.h"

model::model() {
    Motors.emplace_back(0, 0);
    Motors.emplace_back(5, 0);
    Motors.emplace_back(5, 5);
    Motors.emplace_back(0, 5);
}