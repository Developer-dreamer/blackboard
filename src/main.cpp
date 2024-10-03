#include <iostream>
#include <Figures/Circle.h>

#include "Board.h"
#include "BoardMemento.h"
#include "BoardCaretaker.h"
#include "Figures/Rectangle.h"
#include "Figures/Triangle.h"
#include "include/ParseHelper.h"

using namespace std;
int main() {
    Board board;
    BoardMemento memento(board.saveToMemento());
    BoardCaretaker caretaker;
    caretaker.save(memento);

    while (true)
    {
        cout << "Enter the command: ";
        string command;
        cin >> command;

        if (command == "exit")
        {
            return 0;
        } else if (command == "save")
        {
            board.save();
        } else if (command == "load")
        {
            board.load();
        } else if (command == "undo")
        {
            board.restoreFromMemento(caretaker.undo());
        } else if (command == "redo")
        {
            board.restoreFromMemento(caretaker.redo());
        } else if (command == "draw")
        {
            board.draw();
        } else if (command == "list"){
            board.getAllFigures();
        } else if (command == "add")
        {
            vector<string> figure_params = ParseHelper::parseCommand();

            if (figure_params[0] == "circle")
            {
                shared_ptr<IFigure> circle = make_shared<Circle>(figure_params);
                board.addFigure(move(circle));
                caretaker.save(board.saveToMemento());
            } else if (figure_params[0] == "rectangle")
            {
                shared_ptr<IFigure> rectangle = make_shared<Rectangle>(figure_params);
                board.addFigure(move(rectangle));
                caretaker.save(board.saveToMemento());
            } else if (figure_params[0] == "triangle")
            {
                shared_ptr<IFigure> triangle = make_shared<Triangle>(figure_params);
                board.addFigure(move(triangle));
                caretaker.save(board.saveToMemento());
            }
        } else
        {
            cout << "Command not found. Try again..." << endl;
        }

    }
}