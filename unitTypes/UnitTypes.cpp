//
// Created by denysvysochanskyi on 04.04.18.
//

#include "UnitTypes.h"

UnitTypes::UnitTypes(const bool isUndead, const bool isTurnable)
        : isUndead(isUndead), isTurnable(isTurnable) {}

UnitTypes::~UnitTypes() {}

const bool UnitTypes::getIsUndead() const {
    return this->isUndead;
}

const bool UnitTypes::getIsTurnable() const {
    return this->isTurnable;
}
