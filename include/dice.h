#ifndef __DICE__
#define __DICE__

#include <iostream>
class dice
{
    int _face; //private no one can use this

protected: // child classes can use this but not main()
    void set_face(int f) { _face = f; }

public: // everyone can use this
    dice();                 // constructor
    virtual int roll() = 0; // pure virtual function
    int get_face() { return _face; }
    virtual ~dice(); //destructor
};

class dice_normal : public dice
{
public:
    dice_normal();
    /*virtual*/ int roll();
    /*virtual*/ ~dice_normal();
};

class dice_pipe : public dice
{
    int _value;

public:
    dice_pipe(int v) : _value(v) { std::cout << "Dice pipe is constructed! " << std::endl; };
    /*virtual*/ int roll();
    /*virtual*/ ~dice_pipe();
};
#endif