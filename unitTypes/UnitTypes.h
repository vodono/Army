//
// Created by denysvysochanskyi on 04.04.18.
//

#ifndef ARMY_UNITTYPES_H
#define ARMY_UNITTYPES_H


class UnitTypes {
protected:
    const bool isUndead;
    const bool isTurnable;

public:
    UnitTypes(const bool isUndead, const bool isTurnable);
    virtual ~UnitTypes();

    const bool getIsUndead() const;
    const bool getIsTurnable() const;
};


#endif //ARMY_UNITTYPES_H
