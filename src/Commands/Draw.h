#pragma once

#include "ICommand.h"
#include "Board.h"
#include <memory>

using namespace std;

class Draw final: public ICommand
{
public:
    Draw(shared_ptr<Board> receiver);
    void execute() const override;
private:
      Board receiver_;
};