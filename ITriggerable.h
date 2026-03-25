#pragma once

class Gracz;

// -----------------------------------------------------------------------------
// ITriggerable
class ITriggerable {
public:
    virtual void trigger(Gracz& p) = 0;
    virtual ~ITriggerable() = default;
};
